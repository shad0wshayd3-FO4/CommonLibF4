#pragma once

namespace RE
{
	class PerkData
	{
	public:
		// members
		bool        trait;     // 0
		std::int8_t level;     // 1
		std::int8_t numRanks;  // 2
		bool        playable;  // 3
		bool        hidden;    // 4
	};
	static_assert(sizeof(PerkData) == 0x5);
}
