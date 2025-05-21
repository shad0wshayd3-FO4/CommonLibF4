#pragma once

#include "RE/E/ExamineConfirmMenu.h"

namespace RE
{
	class __declspec(novtable) BaseBotConfirmCallback :
		public ExamineConfirmMenu::ICallback  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::__BaseBotConfirmCallback };
		static constexpr auto VTABLE{ VTABLE::__BaseBotConfirmCallback };

		BaseBotConfirmCallback(ExamineMenu* a_thisMenu) :
			ExamineConfirmMenu::ICallback(a_thisMenu)
		{
			REX::EMPLACE_VTABLE(this);
		}

		virtual ~BaseBotConfirmCallback() = default;  // 00

		// override
		virtual void OnAccept() override;  // 01

		F4_HEAP_REDEFINE_NEW(BaseBotConfirmCallback);
	};
	static_assert(sizeof(BaseBotConfirmCallback) == 0x10);
}
