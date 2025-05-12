#pragma once

namespace RE
{
	struct UIMenuEntry
	{
	public:
		using Create_t = IMenu*(const UIMessage&);
		using StaticUpdate_t = void();

		// members
		Scaleform::Ptr<IMenu> menu;                     // 00
		Create_t*             create;                   // 08
		StaticUpdate_t*       staticUpdate{ nullptr };  // 10
	};
	static_assert(sizeof(UIMenuEntry) == 0x18);
}
