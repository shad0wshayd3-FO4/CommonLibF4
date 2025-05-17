#pragma once

namespace RE
{
	class OBJ_TREE
	{
	public:
		// members
		float trunkFlexibility;   // 00
		float branchFlexibility;  // 04
		float trunkAmplitude;     // 08
		float frontAmplitude;     // 0C
		float backAmplitude;      // 10
		float sideAmplitude;      // 14
		float frontFrequency;     // 18
		float backFrequency;      // 1C
		float sideFrequency;      // 20
		float leafFlexibility;    // 24
		float leafAmplitude;      // 28
		float leafFrequency;      // 2C
	};
	static_assert(sizeof(OBJ_TREE) == 0x30);
}
