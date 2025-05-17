#pragma once

#include "RE/H/HolotapeMenu.h"

namespace RE
{
	class __declspec(novtable) TerminalHolotapeMenu :
		public HolotapeMenu  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TerminalHolotapeMenu };
		static constexpr auto VTABLE{ VTABLE::TerminalHolotapeMenu };
		static constexpr auto MENU_NAME{ "TerminalHolotapeMenu"sv };

		virtual ~TerminalHolotapeMenu();  // 00

		// override (HolotapeMenu)
		virtual void ProcessCancel() override;                    // 14
		virtual void ProcessChatterImpl(const Params&) override;  // 15
	};
	static_assert(sizeof(TerminalHolotapeMenu) == 0x108);
}
