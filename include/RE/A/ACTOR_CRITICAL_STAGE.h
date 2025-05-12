#pragma once

namespace RE
{
	enum class ACTOR_CRITICAL_STAGE : std::int32_t
	{
		kNone = 0x0,
		kGooStart = 0x1,
		kGooEnd = 0x2,
		kDisintegrateStart = 0x3,
		kDisintegrateEnd = 0x4,
		kFreezeStart = 0x5,
		kFreezeEnd = 0x6,
	};
}
