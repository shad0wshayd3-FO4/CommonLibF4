#include "F4SE/API.h"

#include "F4SE/Interfaces.h"
#include "F4SE/Logger.h"
#include "F4SE/Trampoline.h"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/msvc_sink.h>

namespace F4SE
{
	namespace Impl
	{
		struct APIStorage
		{
			APIStorage(const APIStorage&) = delete;
			APIStorage(APIStorage&&) = delete;

			APIStorage& operator=(const APIStorage&) = delete;
			APIStorage& operator=(APIStorage&&) = delete;

			[[nodiscard]] static APIStorage& get() noexcept
			{
				static APIStorage singleton;
				return singleton;
			}

			std::string_view pluginName{};
			std::string_view pluginAuthor{};
			REL::Version     pluginVersion{};

			REL::Version                                     f4seVersion{};
			PluginHandle                                     pluginHandle{ static_cast<PluginHandle>(-1) };
			std::uint32_t                                    releaseIndex{ 0 };
			std::function<const void*(F4SEAPI)(const char*)> pluginInfoAccessor;
			std::string_view                                 saveFolderName{};

			MessagingInterface*     messagingInterface{ nullptr };
			ScaleformInterface*     scaleformInterface{ nullptr };
			PapyrusInterface*       papyrusInterface{ nullptr };
			SerializationInterface* serializationInterface{ nullptr };
			TaskInterface*          taskInterface{ nullptr };
			ObjectInterface*        objectInterface{ nullptr };
			TrampolineInterface*    trampolineInterface{ nullptr };

		private:
			APIStorage() noexcept = default;
			~APIStorage() noexcept = default;
		};

		template <class T>
		T* QueryInterface(const LoadInterface* a_intfc, std::uint32_t a_id) noexcept
		{
			auto result = static_cast<T*>(a_intfc->QueryInterface(a_id));
			if (result && result->Version() > T::kVersion) {
				F4SE::WARN("interface definition is out of date");
			}
			return result;
		}

		void InitLog()
		{
			auto path = log::log_directory();
			if (!path)
				return;

			*path /= std::format("{}.log", F4SE::GetPluginName());

			std::vector<spdlog::sink_ptr> sinks{
				std::make_shared<spdlog::sinks::basic_file_sink_mt>(path->string(), true),
				std::make_shared<spdlog::sinks::msvc_sink_mt>()
			};

			auto logger = std::make_shared<spdlog::logger>("global", sinks.begin(), sinks.end());
#ifndef NDEBUG
			logger->set_level(spdlog::level::debug);
			logger->flush_on(spdlog::level::debug);
#else
			logger->set_level(spdlog::level::info);
			logger->flush_on(spdlog::level::info);
#endif
			spdlog::set_default_logger(std::move(logger));
			spdlog::set_pattern("[%T.%e] [%=5t] [%L] %v");
		}
	}

	void Init(const LoadInterface* a_intfc, const bool a_log) noexcept
	{
		if (!a_intfc) {
			stl::report_and_fail("interface is null"sv);
		}

		(void)REL::Module::get();
		(void)REL::IDDB::get();

		auto&       storage = Impl::APIStorage::get();
		const auto& intfc = *a_intfc;

		if (const auto pluginVersionData = PluginVersionData::GetSingleton()) {
			storage.pluginName = pluginVersionData->GetPluginName();
			storage.pluginAuthor = pluginVersionData->GetAuthorName();
			storage.pluginVersion = pluginVersionData->GetPluginVersion();
		}

		storage.f4seVersion = intfc.F4SEVersion();
		storage.pluginHandle = intfc.GetPluginHandle();
		storage.releaseIndex = intfc.GetReleaseIndex();
		storage.pluginInfoAccessor = reinterpret_cast<const Impl::F4SEInterface&>(intfc).GetPluginInfo;
		storage.saveFolderName = intfc.GetSaveFolderName();

		if (a_log) {
			Impl::InitLog();
			F4SE::INFO("{} v{}", GetPluginName(), GetPluginVersion());
		}

		storage.messagingInterface = Impl::QueryInterface<MessagingInterface>(a_intfc, LoadInterface::kMessaging);
		storage.scaleformInterface = Impl::QueryInterface<ScaleformInterface>(a_intfc, LoadInterface::kScaleform);
		storage.papyrusInterface = Impl::QueryInterface<PapyrusInterface>(a_intfc, LoadInterface::kPapyrus);
		storage.serializationInterface = Impl::QueryInterface<SerializationInterface>(a_intfc, LoadInterface::kSerialization);
		storage.taskInterface = Impl::QueryInterface<TaskInterface>(a_intfc, LoadInterface::kTask);
		storage.objectInterface = Impl::QueryInterface<ObjectInterface>(a_intfc, LoadInterface::kObject);
		storage.trampolineInterface = Impl::QueryInterface<TrampolineInterface>(a_intfc, LoadInterface::kTrampoline);
	}

	std::string_view GetPluginName() noexcept
	{
		return Impl::APIStorage::get().pluginName;
	}

	std::string_view GetPluginAuthor() noexcept
	{
		return Impl::APIStorage::get().pluginAuthor;
	}

	REL::Version GetPluginVersion() noexcept
	{
		return Impl::APIStorage::get().pluginVersion;
	}

	REL::Version GetF4SEVersion() noexcept
	{
		return Impl::APIStorage::get().f4seVersion;
	}

	PluginHandle GetPluginHandle() noexcept
	{
		return Impl::APIStorage::get().pluginHandle;
	}

	std::uint32_t GetReleaseIndex() noexcept
	{
		return Impl::APIStorage::get().releaseIndex;
	}

	const PluginInfo* GetPluginInfo(std::string_view a_plugin) noexcept
	{
		if (const auto& accessor = Impl::APIStorage::get().pluginInfoAccessor) {
			if (const auto result = accessor(a_plugin.data())) {
				return static_cast<const PluginInfo*>(result);
			}
		}

		F4SE::WARN("failed to get plugin info for {}", a_plugin);

		return nullptr;
	}

	std::string_view GetSaveFolderName() noexcept
	{
		return Impl::APIStorage::get().saveFolderName;
	}

	const MessagingInterface* GetMessagingInterface() noexcept
	{
		return Impl::APIStorage::get().messagingInterface;
	}

	const ScaleformInterface* GetScaleformInterface() noexcept
	{
		return Impl::APIStorage::get().scaleformInterface;
	}

	const PapyrusInterface* GetPapyrusInterface() noexcept
	{
		return Impl::APIStorage::get().papyrusInterface;
	}

	const SerializationInterface* GetSerializationInterface() noexcept
	{
		return Impl::APIStorage::get().serializationInterface;
	}

	const TaskInterface* GetTaskInterface() noexcept
	{
		return Impl::APIStorage::get().taskInterface;
	}

	const ObjectInterface* GetObjectInterface() noexcept
	{
		return Impl::APIStorage::get().objectInterface;
	}

	const TrampolineInterface* GetTrampolineInterface() noexcept
	{
		return Impl::APIStorage::get().trampolineInterface;
	}

	void AllocTrampoline(std::size_t a_size) noexcept
	{
		auto&      trampoline = GetTrampoline();
		const auto interface = GetTrampolineInterface();
		const auto mem = interface ? interface->AllocateFromBranchPool(a_size) : nullptr;
		if (mem) {
			trampoline.set_trampoline(mem, a_size);
		} else {
			trampoline.create(a_size);
		}
	}
}
