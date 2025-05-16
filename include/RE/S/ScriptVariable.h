#pragma once

#include "RE/B/BSStringT.h"
#include "RE/S/SCRIPT_LOCAL.h"

namespace RE
{
	struct ScriptVariable
	{
	public:
		// members
		SCRIPT_LOCAL data;  // 00
		BSString     name;  // 10
	};
	static_assert(sizeof(ScriptVariable) == 0x20);
}
