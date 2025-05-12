#pragma once

namespace RE
{
	struct PACK_SCHED_DATA
	{
	public:
		// members
		std::int8_t  month;      // 0
		std::int8_t  dayOfWeek;  // 1
		std::int8_t  date;       // 2
		std::int8_t  hour;       // 3
		std::int8_t  min;        // 4
		std::int32_t duration;   // 8
	};
	static_assert(sizeof(PACK_SCHED_DATA) == 0xC);
}
