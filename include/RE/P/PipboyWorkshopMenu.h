#pragma once

#include "RE/P/PipboySubMenu.h"

namespace RE
{
	class __declspec(novtable) PipboyWorkshopMenu :
		public PipboySubMenu  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyWorkshopMenu };
		static constexpr auto VTABLE{ VTABLE::PipboyWorkshopMenu };

		// override (PipboySubMenu)
		void UpdateData() override
		{
			using func_t = decltype(&PipboyWorkshopMenu::UpdateData);
			static REL::Relocation<func_t> func{ REL::ID(2224273) };
			return func(this);
		}
	};
	static_assert(sizeof(PipboyWorkshopMenu) == 0x18);
}
