#pragma once

namespace RE
{
	class MenuModeChangeEvent
	{
	public:
		// members
		BSFixedString menuName;          // 00
		bool          enteringMenuMode;  // 08
	};
	static_assert(sizeof(MenuModeChangeEvent) == 0x10);
}
