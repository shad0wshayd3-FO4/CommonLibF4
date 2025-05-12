#pragma once

namespace RE
{
	struct FACTION_CRIME_DATA
	{
	public:
		// members
		TESObjectREFR*            factionJailMarker;                // 00
		TESObjectREFR*            factionWaitMarker;                // 08
		TESObjectREFR*            factionStolenContainer;           // 10
		TESObjectREFR*            factionPlayerInventoryContainer;  // 18
		BGSListForm*              crimeGroup;                       // 20
		BGSOutfit*                jailOutfit;                       // 28
		FACTION_CRIME_DATA_VALUES crimevalues;                      // 30
	};
	static_assert(sizeof(FACTION_CRIME_DATA) == 0x48);
}
