#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSSpinLock.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSingleton.h"
#include "RE/U/UIMessage.h"

namespace RE
{
	class UIMessageQueue :
		public BSTSingletonSDM<UIMessageQueue>  // 000
	{
	public:
		[[nodiscard]] static UIMessageQueue* GetSingleton()
		{
			static REL::Relocation<UIMessageQueue**> singleton{ ID::UIMessageQueue::Singleton };
			return *singleton;
		}

		void AddMessage(const BSFixedString& a_menu, UI_MESSAGE_TYPE a_type)
		{
			using func_t = decltype(&UIMessageQueue::AddMessage);
			static REL::Relocation<func_t> func{ ID::UIMessageQueue::AddMessage };
			return func(this, a_menu, a_type);
		}

		// members
		BSTSmallArray<std::unique_ptr<UIMessage>, 64> messages;        // 008
		BSSpinLock                                    uiMessagesLock;  // 218
	};
	static_assert(sizeof(UIMessageQueue) == 0x220);
}
