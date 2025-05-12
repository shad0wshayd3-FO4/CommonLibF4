#pragma once

#include "RE/P/PipboySubMenu.h"

namespace RE
{
	class __declspec(novtable) PipboyPerksMenu :
		public PipboySubMenu  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyPerksMenu };
		static constexpr auto VTABLE{ VTABLE::PipboyPerksMenu };

		// override (PipboySubMenu)
		void UpdateData() override
		{
			using func_t = decltype(&PipboyPerksMenu::UpdateData);
			static REL::Relocation<func_t> func{ REL::ID(783380) };
			return func(this);
		}
	};
	static_assert(sizeof(PipboyPerksMenu) == 0x18);
}
