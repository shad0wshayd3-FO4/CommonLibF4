#pragma once

namespace RE
{
	enum class ACTOR_LIFE_STATE : std::int32_t
	{
		kAlive = 0x0,
		kDying = 0x1,
		kDead = 0x2,
		kUnconscious = 0x3,
		kReanimate = 0x4,
		kRecycle = 0x5,
		kRestrained = 0x6,
		kEssentialDown = 0x7,
		kBleedout = 0x8
	};
}
