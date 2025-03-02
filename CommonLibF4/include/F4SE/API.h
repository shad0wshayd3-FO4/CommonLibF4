#pragma once

namespace F4SE
{
	using PluginHandle = std::uint32_t;

	class LoadInterface;

	struct PluginInfo;

	class MessagingInterface;
	class ScaleformInterface;
	class PapyrusInterface;
	class SerializationInterface;
	class TaskInterface;
	class ObjectInterface;
	class TrampolineInterface;

	void Init(const LoadInterface* a_intfc, bool a_log = true) noexcept;

	[[nodiscard]] std::string_view GetPluginName() noexcept;
	[[nodiscard]] std::string_view GetPluginAuthor() noexcept;
	[[nodiscard]] REL::Version     GetPluginVersion() noexcept;

	[[nodiscard]] REL::Version              GetF4SEVersion() noexcept;
	[[nodiscard]] PluginHandle              GetPluginHandle() noexcept;
	[[nodiscard]] std::uint32_t             GetReleaseIndex() noexcept;
	[[nodiscard]] const PluginInfo*         GetPluginInfo(std::string_view a_plugin) noexcept;
	[[nodiscard]] std::string_view          GetSaveFolderName() noexcept;

	[[nodiscard]] const MessagingInterface*     GetMessagingInterface() noexcept;
	[[nodiscard]] const ScaleformInterface*     GetScaleformInterface() noexcept;
	[[nodiscard]] const PapyrusInterface*       GetPapyrusInterface() noexcept;
	[[nodiscard]] const SerializationInterface* GetSerializationInterface() noexcept;
	[[nodiscard]] const TaskInterface*          GetTaskInterface() noexcept;
	[[nodiscard]] const ObjectInterface*        GetObjectInterface() noexcept;
	[[nodiscard]] const TrampolineInterface*    GetTrampolineInterface() noexcept;

	void AllocTrampoline(std::size_t a_size) noexcept;
}
