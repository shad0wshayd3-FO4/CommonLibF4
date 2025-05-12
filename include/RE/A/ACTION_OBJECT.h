#pragma once

namespace RE
{
	struct ACTION_OBJECT
	{
	public:
		// members
		TESForm*      form;   // 00
		std::uint32_t flags;  // 08
	};
	static_assert(sizeof(ACTION_OBJECT) == 0x10);
}
