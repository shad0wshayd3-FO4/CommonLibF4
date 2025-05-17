#pragma once

namespace RE
{
	class CombatStyleMeleeData
	{
	public:
		// members
		float attackIncapacitatedMult;       // 00
		float powerAttackIncapacitatedMult;  // 04
		float powerAttackBlockingMult;       // 08
		float bashMult;                      // 0C
		float bashRecoiledMult;              // 10
		float bashAttackMult;                // 14
		float bashPowerAttackMult;           // 18
		float specialAttackMult;             // 1C
		float blockWhenIncapacitatedMult;    // 20
		float attackWhenIncapacitatedMult;   // 24
	};
	static_assert(sizeof(CombatStyleMeleeData) == 0x28);
}
