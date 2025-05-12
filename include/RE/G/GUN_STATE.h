#pragma once

namespace RE
{
	enum class GUN_STATE : std::int32_t
	{
		kDrawn = 0x0,
		kRelaxed = 0x1,
		kBlocked = 0x2,
		kAlert = 0x3,
		kReloading = 0x4,
		kThrowing = 0x5,
		kSighted = 0x6,
		kFire = 0x7,
		kFireSighted = 0x8
	};
}
