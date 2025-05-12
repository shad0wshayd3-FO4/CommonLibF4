#pragma once

namespace RE
{
	struct FACTION_DATA
	{
	public:
		// members
		std::uint32_t flags;  // 0
	};
	static_assert(sizeof(FACTION_DATA) == 0x4);
}
