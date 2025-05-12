#pragma once

namespace RE
{
	enum class SOUND_LEVEL : std::int32_t
	{
		kLoud = 0x0,
		kNormal = 0x1,
		kSilent = 0x2,
		kVeryLoud = 0x3,
		kQuiet = 0x4,
		kCount = 0x5
	};
}
