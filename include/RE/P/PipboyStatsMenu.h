#pragma once

#include "RE/B/BSSoundHandle.h"
#include "RE/P/PipboySubMenu.h"

namespace RE
{
	class __declspec(novtable) PipboyStatsMenu :
		public PipboySubMenu  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyStatsMenu };
		static constexpr auto VTABLE{ VTABLE::PipboyStatsMenu };

		// override (PipboySubMenu)
		void UpdateData() override
		{
			using func_t = decltype(&PipboyStatsMenu::UpdateData);
			static REL::Relocation<func_t> func{ ID::PipboyStatsMenu::UpdateData };
			return func(this);
		}

		// members
		BSSoundHandle perkSound;  // 18
	};
	static_assert(sizeof(PipboyStatsMenu) == 0x20);
}
