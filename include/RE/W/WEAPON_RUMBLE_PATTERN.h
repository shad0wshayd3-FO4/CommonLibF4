#pragma once

namespace RE
{
	enum class WEAPON_RUMBLE_PATTERN : std::int32_t
	{
		kConstant = 0x0,
		kPeriodicSquare = 0x1,
		kPeriodicTriangle = 0x2,
		kPeriodicSawtooth = 0x3,
		kPatternCount = 0x4
	};
}
