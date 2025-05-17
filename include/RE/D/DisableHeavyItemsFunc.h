#pragma once

namespace RE
{
	class DisableHeavyItemsFunc
	{
	public:
		// members
		float playerCurrEncumbrance;     // 00
		float playerMaxEncumbrance;      // 04
		float containerCurrEncumbrance;  // 08
		float containerMaxEncumbrance;   // 0C
	};
	static_assert(sizeof(DisableHeavyItemsFunc) == 0x10);
}
