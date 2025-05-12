#pragma once

namespace RE
{
	class __declspec(novtable) PipboyPlayerInfoMenu :
		public PipboySubMenu  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyPlayerInfoMenu };
		static constexpr auto VTABLE{ VTABLE::PipboyPlayerInfoMenu };

		// override (PipboySubMenu)
		void UpdateData() override
		{
			using func_t = decltype(&PipboyPlayerInfoMenu::UpdateData);
			static REL::Relocation<func_t> func{ REL::ID(426990) };
			return func(this);
		}
	};
	static_assert(sizeof(PipboyPlayerInfoMenu) == 0x18);
}
