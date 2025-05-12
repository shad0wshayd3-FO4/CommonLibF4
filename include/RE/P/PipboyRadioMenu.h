#pragma once

#include "RE/P/PipboySubMenu.h"

namespace RE
{
	class __declspec(novtable) PipboyRadioMenu :
		public PipboySubMenu  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyRadioMenu };
		static constexpr auto VTABLE{ VTABLE::PipboyRadioMenu };

		// override (PipboySubMenu)
		void UpdateData() override
		{
			using func_t = decltype(&PipboyRadioMenu::UpdateData);
			static REL::Relocation<func_t> func{ REL::ID(713423) };
			return func(this);
		}

		bool radioModeOn;  // 18
	};
	static_assert(sizeof(PipboyRadioMenu) == 0x20);

}
