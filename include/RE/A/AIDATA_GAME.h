#pragma once

namespace RE
{
	struct AIDATA_GAME
	{
	public:
		// members
		std::uint32_t aggression : 2;      // 00:00
		std::uint32_t confidence : 3;      // 00:02
		std::uint32_t energy : 8;          // 00:05
		std::uint32_t morality : 2;        // 00:13
		std::uint32_t unused : 3;          // 00:15
		std::uint32_t assistance : 2;      // 00:18
		std::uint32_t useAggroRadius : 1;  // 00:20
		std::uint16_t aggroRadius[3];     // 04
		std::uint32_t noSlowApproach : 1;  // 0A:00
	};
	static_assert(sizeof(AIDATA_GAME) == 0x10);
}
