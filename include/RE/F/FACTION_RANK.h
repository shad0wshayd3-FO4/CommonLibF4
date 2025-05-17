#pragma once

namespace RE
{
	class FACTION_RANK
	{
	public:
		// members
		TESFaction* faction;  // 00
		std::int8_t rank;     // 08
	};
	static_assert(sizeof(FACTION_RANK) == 0x10);
}
