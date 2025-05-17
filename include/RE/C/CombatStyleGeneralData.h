#pragma once

namespace RE
{
	class CombatStyleGeneralData
	{
	public:
		// members
		float offensiveMult;       // 00
		float defensiveMult;       // 04
		float groupOffensiveMult;  // 08
		float meleeScoreMult;      // 0C
		float magicScoreMult;      // 10
		float rangedScoreMult;     // 14
		float shoutScoreMult;      // 18
		float unarmedScoreMult;    // 1C
		float staffScoreMult;      // 20
		float avoidThreatChance;   // 24
		float dodgeThreatChance;   // 28
		float evadeThreatChance;   // 2C
	};
	static_assert(sizeof(CombatStyleGeneralData) == 0x30);
}
