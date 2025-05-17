#pragma once

#include "RE/P/PipboySubMenu.h"

namespace RE
{
	class __declspec(novtable) PipboySpecialMenu :
		public PipboySubMenu  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboySpecialMenu };
		static constexpr auto VTABLE{ VTABLE::PipboySpecialMenu };

		// override (PipboySubMenu)
		void UpdateData() override
		{
			using func_t = decltype(&PipboySpecialMenu::UpdateData);
			static REL::Relocation<func_t> func{ ID::PipboySpecialMenu::UpdateData };
			return func(this);
		}
	};
	static_assert(sizeof(PipboySpecialMenu) == 0x18);
}
