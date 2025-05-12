#pragma once

#include "RE/P/PipboySubMenu.h"

namespace RE
{
	class __declspec(novtable) PipboyInventoryMenu :
		public PipboySubMenu  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyInventoryMenu };
		static constexpr auto VTABLE{ VTABLE::PipboyInventoryMenu };

		// override (PipboySubMenu)
		void UpdateData() override
		{
			using func_t = decltype(&PipboyInventoryMenu::UpdateData);
			static REL::Relocation<func_t> func{ REL::ID(2224143) };
			return func(this);
		}

		void SetQuickkey(int a_selectedIndex, int a_quickkeyIndex)
		{
			using func_t = decltype(&PipboyInventoryMenu::SetQuickkey);
			static REL::Relocation<func_t> func{ REL::ID(2224159) };
			return func(this, a_selectedIndex, a_quickkeyIndex);
		}
	};
	static_assert(sizeof(PipboyInventoryMenu) == 0x18);
}
