#pragma once

namespace RE
{
	class __declspec(novtable) ButtonHintBar :
		public BSGFxShaderFXTarget  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ButtonHintBar };
		static constexpr auto VTABLE{ VTABLE::ButtonHintBar };

		// members
		Scaleform::GFx::Value sourceButtons;            // B0
		bool                  redirectToButtonBarMenu;  // D0
		bool                  isTopButtonBar;           // D1
	};
	static_assert(sizeof(ButtonHintBar) == 0xD8);
}
