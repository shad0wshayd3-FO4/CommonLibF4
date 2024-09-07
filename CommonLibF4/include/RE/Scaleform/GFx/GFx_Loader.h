#pragma once

#include "RE/Scaleform/GFx/GFx_Resource.h"
#include "RE/Scaleform/Kernel/SF_RefCount.h"
#include "RE/Scaleform/Kernel/SF_System.h"
#include "RE/Scaleform/Kernel/SF_Types.h"

namespace RE::Scaleform::GFx
{
	class LoaderImpl;
	class MovieDef;
	class ResourceLib;
	class System;

	class __declspec(novtable) State :
		public RefCountBase<State, 2>  // 00
	{
	public:
		enum class StateType : std::int32_t
		{
			kNone,

			kTranslator,
			kLog,
			kActionControl,
			kUserEventHandler,
			kFSCommandHandler,
			kExternalInterface,
			kMultitouchInterface,
			kVirtualKeyboardInterface,

			kFileOpener,
			kURLBuilder,
			kImageCreator,
			kImageFileHandlerRegistry,
			kParseControl,
			kProgressHandler,
			kImportVisitor,
			kFontPackParams,
			kFontLib,
			kFontProvider,
			kFontMap,
			kTaskManager,
			kTextClipboard,
			kTextKeyMap,
			kIMEManager,
			kXMLSupport,
			kZlibSupport,
			kFontCompactorParams,
			kImagePackerParams,
			kAudio,
			kVideo,
			kTestStream,
			kSharedObject,
			kLocSupport,

			kAS2Support,
			kAS3Support
		};

		State(StateType a_type = StateType::kNone) :
			sType(a_type)
		{}

		[[nodiscard]] constexpr StateType GetStateType() const noexcept { return sType; }

	protected:
		// members
		StateType sType;  // 10
	};
	static_assert(sizeof(State) == 0x18);

	class __declspec(novtable) Translator :
		public State
	{
	public:
		enum class WordWrappingType : std::uint32_t
		{
			kDefault = 0,
			kAsian = 1 << 0,
			kProhibition = 1 << 1,
			kNoHangulWrap = 1 << 2,
			kHyphenation = 1 << 3,
			kCustom = 0x80
		};

		Translator() :
			State(StateType::kTranslator)
		{}

		explicit Translator(Flags<WordWrappingType> a_wwMode) :
			State(StateType::kTranslator), wwMode(a_wwMode)
		{}

		// members
		Flags<WordWrappingType> wwMode;  // 18
	};
	static_assert(sizeof(Translator) == 0x20);

	class __declspec(novtable) ActionControl :
		public State  // 00
	{
	public:
		enum class ActionControlFlags : std::uint32_t
		{
			kVerbose = 0x01,
			kErrorSuppress = 0x02,
			kLogRootFilenames = 0x04,
			kLogChildFilenames = 0x08,
			kLogAllFilenames = 0x04 | 0x08,
			kLongFilenames = 0x10
		};

		ActionControl(Flags<ActionControlFlags> a_actionFlags = ActionControlFlags::kLogChildFilenames) :
			State(StateType::kActionControl), actionFlags(a_actionFlags)
		{}

		// members
		Flags<ActionControlFlags> actionFlags;  // 18
	};
	static_assert(sizeof(ActionControl) == 0x20);

	class __declspec(novtable) UserEventHandler :
		public State  // 00
	{
	public:
		UserEventHandler() :
			State(StateType::kUserEventHandler)
		{}

		virtual void HandleEvent(class Movie* pmovie, const class Event& event) = 0;
	};
	static_assert(sizeof(UserEventHandler) == 0x18);

	class __declspec(novtable) FSCommandHandler :
		public State  // 00
	{
	public:
		FSCommandHandler() :
			State(StateType::kFSCommandHandler)
		{}

		virtual void HandleEvent(class Movie* pmovie, const class Event& event) = 0;
	};
	static_assert(sizeof(FSCommandHandler) == 0x18);

	class __declspec(novtable) StateBag :
		public FileTypeConstants  // 00
	{
	protected:
		// add
		virtual StateBag* GetStateBagImpl() const { return nullptr; }  // 00

	public:
		virtual ~StateBag() = default;  // 01

		// NOLINTNEXTLINE(misc-no-recursion)
		virtual void SetState(State::StateType a_stateType, State* a_state)  // 02
		{
			assert(a_state ? true : a_state->GetStateType() == a_stateType);
			const auto bag = GetStateBagImpl();
			if (bag) {
				bag->SetState(a_stateType, a_state);
			}
		}

		// NOLINTNEXTLINE(misc-no-recursion)
		virtual State* GetStateAddRef(State::StateType a_stateType) const  // 03
		{
			const auto bag = GetStateBagImpl();
			return bag ? bag->GetStateAddRef(a_stateType) : nullptr;
		}

		virtual void GetStatesAddRef(State** a_states, const State::StateType* a_stateTypes, std::uint32_t a_count) const  // 04
		{
			const auto bag = GetStateBagImpl();
			if (bag) {
				bag->GetStatesAddRef(a_states, a_stateTypes, a_count);
			}
		}
	};
	static_assert(sizeof(StateBag) == 0x8);

	struct ExporterInfo
	{
	public:
		enum class ExportFlagConstants : std::uint32_t
		{
			kGlyphTexturesExported = 1 << 0,
			kGradientTexturesExported = 1 << 1,
			kGlyphsStripped = 1 << 4
		};

		// members
		Flags<FileTypeConstants::FileFormatType> format;       // 00
		const char*                              prefix;       // 08
		const char*                              swfName;      // 10
		std::uint16_t                            version;      // 18
		Flags<ExportFlagConstants>               exportFlags;  // 1C
	};
	static_assert(sizeof(ExporterInfo) == 0x20);

	class __declspec(novtable) Loader :
		public StateBag  // 00
	{
	public:
		enum class LoadConstants : std::uint32_t
		{
			kAll = 0,
			kWaitCompletion = 1 << 0,
			kWaitFrame1 = 1 << 1,
			kOrdered = 1 << 4,
			kOnThread = 1 << 6,
			kKeepBindData = 1 << 7,
			kImageFiles = 1 << 16,
			kDisableSWF = 1 << 19,
			kDisableImports = 1 << 20,
			kQuietOpen = 1 << 21,

			kDebugHeap = 1 << 28
		};

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~Loader();  // 00

		// add
		virtual bool CheckTagLoader(std::int32_t a_tagType) const;  // 04

		[[nodiscard]] MovieDef* CreateMovie(const char* a_filename, Flags<LoadConstants> a_loadConstants = LoadConstants::kAll, std::size_t a_memoryArena = 0)
		{
			using func_t = decltype(&Loader::CreateMovie);
			static REL::Relocation<func_t> func{ REL::ID(2284723) };
			return func(this, a_filename, a_loadConstants, a_memoryArena);
		}

		// members
		LoaderImpl*          impl;               // 08
		ResourceLib*         strongResourceLib;  // 10
		Flags<LoadConstants> defLoadFlags;       // 18
	};
	static_assert(sizeof(Loader) == 0x20);

	class System :
		public Scaleform::System  // 0
	{
	public:
	};
	static_assert(std::is_empty_v<System>);
}
