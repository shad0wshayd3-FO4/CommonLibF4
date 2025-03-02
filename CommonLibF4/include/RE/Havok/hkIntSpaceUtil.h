#pragma once

#include "RE/Havok/hkAabb.h"
#include "RE/Havok/hkVector4.h"

namespace RE
{
	class hkIntSpaceUtil
	{
	public:
		hkVector4f bitOffsetLow;
		hkVector4f bitOffsetHigh;
		hkVector4f bitScale;
		hkVector4f bitScaleInv;
		hkAabb     aabb;
	};
	static_assert(sizeof(hkIntSpaceUtil) == 0x60);
}
