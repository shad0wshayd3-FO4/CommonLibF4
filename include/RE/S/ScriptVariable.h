#pragma once

namespace RE
{
	struct ScriptVariable
	{
	public:
		// members
		SCRIPT_LOCAL    data;  // 00
		BSStringT<char> name;  // 10
	};
	static_assert(sizeof(ScriptVariable) == 0x20);
}
