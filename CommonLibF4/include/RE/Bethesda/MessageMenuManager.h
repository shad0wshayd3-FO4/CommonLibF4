#pragma once

#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSStringT.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTSingleton.h"
#include "RE/Bethesda/BSTSmartPointer.h"
#include "RE/Bethesda/UIMessage.h"

namespace RE
{
	enum class UI_DEPTH_PRIORITY;

	enum class WARNING_TYPES
	{
		kDefault,
		kSystem,
		kCombat,
		kAnimation,
		kAI,
		kScripts,
		kSaveLoad,
		kDialogue,
		kQuests,
		kPackages,
		kEditor,
		kModels,
		kTextures,
		kPlugins,
		kMasterFile,
		kForms,
		kMagic,
		kShaders,
		kRendering,
		kPathfinding,
		kMenus,
		kAudio,
		kCells,
		kHavok,
		kFaceGen,
		kWater,
		kInGameMessage,
		kMemory,
		kPerformance,
		kLootJoy,
		kVATS,
		kDismember,
		kCompanion,
		kWorkshop,
	};

	class alignas(0x10) IMessageBoxCallback :
		public BSIntrusiveRefCounted  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::IMessageBoxCallback };
		static constexpr auto VTABLE{ VTABLE::IMessageBoxCallback };

		virtual ~IMessageBoxCallback() = default;  // 00

		// add
		virtual void operator()(std::uint8_t a_buttonIdx) = 0;  // 01
	};
	static_assert(sizeof(IMessageBoxCallback) == 0x10);

	class __declspec(novtable) MessageBoxData :
		public IUIMessageData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::MessageBoxData };
		static constexpr auto VTABLE{ VTABLE::MessageBoxData };

		// members
		BSStringT<char>                                headerText;      // 18
		BSStringT<char>                                bodyText;        // 28
		BSTArray<BSStringT<char>>                      buttonText;      // 38
		REX::EnumSet<WARNING_TYPES, std::uint32_t>     warningContext;  // 50
		BSTSmartPointer<IMessageBoxCallback>           callback;        // 58
		REX::EnumSet<UI_DEPTH_PRIORITY, std::uint32_t> menuDepth;       // 60
		bool                                           modal;           // 64
		bool                                           ensureUnique;    // 65
	};
	static_assert(sizeof(MessageBoxData) == 0x68);

	class MessageMenuManager :
		public BSTSingletonSDM<MessageMenuManager>  // 00
	{
	public:
		[[nodiscard]] static MessageMenuManager* GetSingleton()
		{
			static REL::Relocation<MessageMenuManager**> singleton{ REL::ID(2689087) };
			return *singleton;
		}

		void Create(
			const char*          a_headerText,
			const char*          a_bodyText,
			IMessageBoxCallback* a_callback,
			WARNING_TYPES        a_warningContext,
			const char*          a_button1Text = nullptr,
			const char*          a_button2Text = nullptr,
			const char*          a_button3Text = nullptr,
			const char*          a_button4Text = nullptr,
			bool                 a_ensureUnique = false)
		{
			using func_t = decltype(&MessageMenuManager::Create);
			static REL::Relocation<func_t> func{ REL::ID(2249456) };
			return func(this, a_headerText, a_bodyText, a_callback, a_warningContext, a_button1Text, a_button2Text, a_button3Text, a_button4Text, a_ensureUnique);
		}

		// members
		BSReadWriteLock                            messageRWLock;          // 04
		BSTArray<MessageBoxData*>                  messages;               // 10
		REX::EnumSet<WARNING_TYPES, std::uint32_t> currentWarningContext;  // 28
		bool                                       disabledWarnings[34];   // 2C
	};
	static_assert(sizeof(MessageMenuManager) == 0x50);
}
