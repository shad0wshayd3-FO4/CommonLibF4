#pragma once

#include "RE/P/PipboySubMenu.h"

namespace RE
{
	class __declspec(novtable) PipboyLogMenu :
		public PipboySubMenu  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyLogMenu };
		static constexpr auto VTABLE{ VTABLE::PipboyLogMenu };

		// override (PipboySubMenu)
		void UpdateData() override
		{
			using func_t = decltype(&PipboyLogMenu::UpdateData);
			static REL::Relocation<func_t> func{ ID::PipboyLogMenu::UpdateData };
			return func(this);
		}
	};
	static_assert(sizeof(PipboyLogMenu) == 0x18);
}
