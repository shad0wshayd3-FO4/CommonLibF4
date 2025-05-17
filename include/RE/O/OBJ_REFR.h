#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	class OBJ_REFR
	{
	public:
		// members
		NiPoint3A       angle;            // 00
		NiPoint3A       location;         // 10
		TESBoundObject* objectReference;  // 20
	};
	static_assert(sizeof(OBJ_REFR) == 0x30);
}
