#pragma once

namespace RE
{
	class QUEST_DATA
	{
	public:
		// members
		float         questDelayTime;  // 00
		std::uint16_t flags;           // 04
		std::int8_t   priority;        // 06
		std::int8_t   questType;       // 07
	};
	static_assert(sizeof(QUEST_DATA) == 0x8);
}
