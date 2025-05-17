#pragma once

#include "Scaleform/R/RefCountBase.h"

namespace Scaleform::GFx
{
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
}
