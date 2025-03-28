#pragma once

#include "RE/Havok/hkHandle.h"

namespace RE
{
	struct hknpMotionIdBaseDiscriminant;

	struct hknpMotionId :
		public hkHandle<std::uint32_t, 0x7FFF'FFFF, hknpMotionIdBaseDiscriminant>
	{};
	static_assert(sizeof(hknpMotionId) == 0x4);
}
