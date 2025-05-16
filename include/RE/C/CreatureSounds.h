#pragma once

#include "RE/B/BSTArray.h"

namespace RE
{
	struct CREATURE_SOUND;

	class CreatureSounds
	{
	public:
		// members
		BSTArray<CREATURE_SOUND> consciousLoops;           // 00
		bool                     stopLoopWhenUnconscious;  // 18
	};
	static_assert(sizeof(CreatureSounds) == 0x20);
}
