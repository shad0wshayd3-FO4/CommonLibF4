#pragma once

namespace RE
{
	struct PerkRankData
	{
	public:
		PerkRankData(BGSPerk* a_perk, std::int8_t a_rank) :
			perk(a_perk), currentRank(a_rank)
		{
		}

		F4_HEAP_REDEFINE_NEW(PerkRankData);

		// members
		BGSPerk*    perk;         // 00
		std::int8_t currentRank;  // 08
	};
	static_assert(sizeof(PerkRankData) == 0x10);
}
