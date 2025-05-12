#pragma once

namespace RE
{
	class __declspec(novtable) PipboyHolotapeMenu :
		public HolotapeMenu  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PipboyHolotapeMenu };
		static constexpr auto VTABLE{ VTABLE::PipboyHolotapeMenu };
		static constexpr auto MENU_NAME{ "PipboyHolotapeMenu"sv };

		virtual ~PipboyHolotapeMenu();  // 00

		// override (HolotapeMenu)
		virtual void ProcessCancel() override;  // 14

		// members
		bool wasPipboyActive;  // 108
	};
	static_assert(sizeof(PipboyHolotapeMenu) == 0x110);
}
