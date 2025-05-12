#pragma once

namespace RE
{
	struct IDLE_DATA
	{
	public:
		// members
		std::int8_t   loopMin;      // 0
		std::int8_t   loopMax;      // 1
		std::int8_t   flags;        // 2
		std::uint16_t replayDelay;  // 4
	};
	static_assert(sizeof(IDLE_DATA) == 0x6);
}
