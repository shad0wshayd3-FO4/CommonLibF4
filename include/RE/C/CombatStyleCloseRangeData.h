#pragma once

namespace RE
{
	class CombatStyleCloseRangeData
	{
	public:
		// members
		float         circleMult;               // 00
		float         fallbackMult;             // 04
		float         flankDistanceMult;        // 08
		float         stalkTimeMult;            // 0C
		float         chargeDistanceMult;       // 10
		float         flipThrowProbability;     // 14
		float         sprintChargeProbability;  // 18
		float         sideswipeProbability;     // 1C
		float         disengageProbability;     // 20
		std::uint32_t throwMaxTargets;          // 24
		float         flankVarianceMult;        // 28
	};
	static_assert(sizeof(CombatStyleCloseRangeData) == 0x2C);
}
