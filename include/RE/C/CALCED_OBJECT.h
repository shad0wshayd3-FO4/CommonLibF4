#pragma once

#include "RE/C/ContainerItemExtra.h"
#include "RE/I/INSTANCE_FILTER.h"

namespace RE
{
	struct CALCED_OBJECT
	{
	public:
		// members
		TESBoundObject*    object;          // 00
		const char*        overrideName;    // 08
		std::int32_t       count;           // 10
		ContainerItemExtra itemExtra;       // 18
		INSTANCE_FILTER    instanceFilter;  // 30
	};
	static_assert(sizeof(CALCED_OBJECT) == 0x58);
}
