#pragma once

#include "RE/G/GameMenuBase.h"

namespace RE
{
	class __declspec(novtable) TerminalMenuButtons :
		public GameMenuBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TerminalMenuButtons };
		static constexpr auto VTABLE{ VTABLE::TerminalMenuButtons };
		static constexpr auto MENU_NAME{ "TerminalMenuButtons"sv };

		virtual ~TerminalMenuButtons();  // 00

		// override (GameMenuBase)
		virtual void               Call(const Params&) override;                   // 01
		virtual void               MapCodeObjectFunctions() override;              // 02
		virtual UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;  // 03
	};
	static_assert(sizeof(TerminalMenuButtons) == 0xE0);
}
