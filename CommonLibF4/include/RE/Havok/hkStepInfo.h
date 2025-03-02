#pragma once

#include "RE/Havok/hkBaseTypes.h"

namespace RE
{
	class hkStepInfo
	{
	public:
		// members
		hkPadSpu<float> startTime;     // 00
		hkPadSpu<float> endTime;       // 04
		hkPadSpu<float> deltaTime;     // 08
		hkPadSpu<float> invDeltaTime;  // 0C
	};
	static_assert(sizeof(hkStepInfo) == 0x10);
}
