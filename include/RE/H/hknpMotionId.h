#pragma once

#include "RE/H/hkHandle.h"

namespace RE
{
	class hknpMotionIdBaseDiscriminant
	{
	public:
	};
	static_assert(std::is_empty_v<hknpMotionIdBaseDiscriminant>);

	class hknpMotionId :
		public hkHandle<std::uint32_t, 2147483647, hknpMotionIdBaseDiscriminant>
	{
	public:
	};
	static_assert(sizeof(hknpMotionId) == 0x04);
}
