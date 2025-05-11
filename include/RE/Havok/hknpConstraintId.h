#pragma once

#include "RE/Havok/hkHandle.h"

namespace RE
{
	struct hknpConstraintIdBaseDiscriminant;

	struct hknpConstraintId :
		public hkHandle<std::uint32_t, 0x7FFF'FFFF, hknpConstraintIdBaseDiscriminant>
	{};
	static_assert(sizeof(hknpConstraintId) == 0x4);
}
