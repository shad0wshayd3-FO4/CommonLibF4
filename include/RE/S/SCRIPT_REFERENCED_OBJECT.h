#pragma once

#include "RE/B/BSStringT.h"

namespace RE
{
	class SCRIPT_REFERENCED_OBJECT
	{
	public:
		// members
		BSString      editorID;    // 00
		TESForm*      form;        // 10
		std::uint32_t variableID;  // 18
	};
	static_assert(sizeof(SCRIPT_REFERENCED_OBJECT) == 0x20);
}
