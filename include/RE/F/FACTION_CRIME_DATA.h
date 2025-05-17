#pragma once

#include "RE/F/FACTION_CRIME_DATA_VALUES.h"

namespace RE
{
	class FACTION_CRIME_DATA
	{
	public:
		// members
		TESObjectREFR*            factionJailMarker;                // 00
		TESObjectREFR*            factionWaitMarker;                // 08
		TESObjectREFR*            factionStolenContainer;           // 10
		TESObjectREFR*            factionPlayerInventoryContainer;  // 18
		BGSListForm*              crimeGroup;                       // 20
		BGSOutfit*                jailOutfit;                       // 28
		FACTION_CRIME_DATA_VALUES crimeValues;                      // 30
	};
	static_assert(sizeof(FACTION_CRIME_DATA) == 0x48);
}
