#pragma once

namespace RE
{
	struct TESObjectSTATData
	{
	public:
		// members
		BGSMaterialObject* materialObj;             // 00
		float              materialThresholdAngle;  // 08
		float              leafAmplitude;           // 0C
		float              leafFrequency;           // 10
	};
	static_assert(sizeof(TESObjectSTATData) == 0x18);
}
