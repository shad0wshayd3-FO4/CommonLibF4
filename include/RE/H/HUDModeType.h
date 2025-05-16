#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	class HUDModeType
	{
	public:
		HUDModeType(const char* a_modeString) :
			modeString(a_modeString)
		{}

		// members
		BSFixedString modeString;  // 0
	};
	static_assert(sizeof(HUDModeType) == 0x8);
}
