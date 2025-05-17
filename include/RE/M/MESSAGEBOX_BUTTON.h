#pragma once

#include "RE/B/BGSLocalizedString.h"
#include "RE/T/TESCondition.h"

namespace RE
{
	class MESSAGEBOX_BUTTON
	{
	public:
		// members
		BGSLocalizedString text;        // 00
		TESCondition       conditions;  // 08
	};
	static_assert(sizeof(MESSAGEBOX_BUTTON) == 0x10);
}
