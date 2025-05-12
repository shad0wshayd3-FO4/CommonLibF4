#pragma once

namespace RE
{
	struct MESSAGEBOX_BUTTON
	{
	public:
		// members
		BGSLocalizedString text;        // 00
		TESCondition       conditions;  // 08
	};
	static_assert(sizeof(MESSAGEBOX_BUTTON) == 0x10);
}
