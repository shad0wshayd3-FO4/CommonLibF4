#pragma once

namespace RE
{
	struct CombatStyleLongRangeData
	{
	public:
		// members
		float strafeMult;       // 00
		float adjustRangeMult;  // 04
		float crouchMult;       // 08
		float waitMult;         // 0C
		float rangeMult;        // 10
	};
	static_assert(sizeof(CombatStyleLongRangeData) == 0x14);
}
