#pragma once

namespace RE
{
	enum class LOCK_LEVEL
	{
		kUnlocked = static_cast<std::underlying_type_t<BIPED_OBJECT>>(-1),
		kEasy = 0x0,
		kAverage = 0x1,
		kHard = 0x2,
		kVeryHard = 0x3,
		kRequiresKey = 0x4,
		kInaccessible = 0x5,
		kTerminal = 0x6,
		kBarred = 0x7,
		kChained = 0x8,
	};
}
