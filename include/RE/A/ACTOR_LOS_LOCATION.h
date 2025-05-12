#pragma once

namespace RE
{
	enum class ACTOR_LOS_LOCATION : std::int32_t
	{
		kNone = 0x0,
		kEye = 0x1,
		kHead = 0x2,
		kTorse = 0x3,
		kFeet = 0x4,
		kCount = 0x5
	};
}
