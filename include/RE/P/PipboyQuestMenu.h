#pragma once

#include "RE/P/PipboySubMenu.h"

namespace RE
{
	class __declspec(novtable) PipboyQuestMenu :
		public PipboySubMenu  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyQuestMenu };
		static constexpr auto VTABLE{ VTABLE::PipboyQuestMenu };

		// override (PipboySubMenu)
		void UpdateData() override
		{
			using func_t = decltype(&PipboyQuestMenu::UpdateData);
			static REL::Relocation<func_t> func{ REL::ID(2224231) };
			return func(this);
		}
	};
	static_assert(sizeof(PipboyQuestMenu) == 0x18);
}
