#pragma once

namespace RE
{
	class FACTION_DATA
	{
	public:
		// members
		std::uint32_t flags;  // 0
	};
	static_assert(sizeof(FACTION_DATA) == 0x4);
}
