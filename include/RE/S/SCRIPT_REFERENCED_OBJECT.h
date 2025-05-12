#pragma once

namespace RE
{
	struct SCRIPT_REFERENCED_OBJECT
	{
	public:
		// members
		BSStringT<char> editorID;    // 00
		TESForm*        form;        // 10
		std::uint32_t   variableID;  // 18
	};
	static_assert(sizeof(SCRIPT_REFERENCED_OBJECT) == 0x20);
}
