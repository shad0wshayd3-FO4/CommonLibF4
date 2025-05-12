#pragma once

namespace RE
{
	class CreatureSounds
	{
	public:
		// members
		BSTArray<CREATURE_SOUND> consciousLoops;           // 00
		bool                     stopLoopWhenUnconscious;  // 18
	};
	static_assert(sizeof(CreatureSounds) == 0x20);
}
