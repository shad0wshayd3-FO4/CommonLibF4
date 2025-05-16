#pragma once

#include "RE/P/PACK_SCHED_DATA.h"

namespace RE
{
	class PackageSchedule
	{
	public:
		// members
		PACK_SCHED_DATA psData;  // 0
	};
	static_assert(sizeof(PackageSchedule) == 0xC);
}
