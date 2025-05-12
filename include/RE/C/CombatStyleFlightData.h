#pragma once

namespace RE
{
	struct CombatStyleFlightData
	{
	public:
		// members
		float hoverChance;           // 00
		float diveBombChance;        // 04
		float groundAttackChance;    // 08
		float hoverTimeMult;         // 0C
		float groundAttackTimeMult;  // 10
		float perchAttackChance;     // 14
		float perchAttackTimeMult;   // 18
		float flyingAttackChance;    // 1C
	};
	static_assert(sizeof(CombatStyleFlightData) == 0x20);
}
