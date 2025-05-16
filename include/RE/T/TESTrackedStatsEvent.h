#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	struct TESTrackedStatsEvent
	{
		// members
		BSFixedString stat;   // 00
		std::int32_t  value;  // 08
	};
	static_assert(sizeof(TESTrackedStatsEvent) == 0x10);
}
