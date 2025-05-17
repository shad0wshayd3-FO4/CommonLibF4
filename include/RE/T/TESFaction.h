#pragma once

#include "RE/A/AITimeStamp.h"
#include "RE/B/BSSimpleList.h"
#include "RE/B/BSTHashMap.h"
#include "RE/F/FACTION_CRIME_DATA.h"
#include "RE/F/FACTION_DATA.h"
#include "RE/F/FACTION_VENDOR_DATA.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESReactionForm.h"

namespace RE
{
	class RANK_DATA;

	class __declspec(novtable) TESFaction :
		public TESForm,         // 000
		public TESFullName,     // 020
		public TESReactionForm  // 030
	{
	public:
		static constexpr auto RTTI{ RTTI::TESFaction };
		static constexpr auto VTABLE{ VTABLE::TESFaction };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kFACT };

		// members
		BSTHashMap<const TESNPC*, std::uint32_t>* crimeGoldMap;           // 50
		FACTION_DATA                              data;                   // 58
		FACTION_CRIME_DATA                        crimeData;              // 60
		FACTION_VENDOR_DATA                       vendorData;             // A8
		BSSimpleList<RANK_DATA*>                  rankDataList;           // E0
		std::int32_t                              majorCrime;             // F0
		std::int32_t                              minorCrime;             // F4
		AITimeStamp                               resistArrestTimeStamp;  // F8
		float                                     enemyFlagTimeStamp;     // FC
	};
	static_assert(sizeof(TESFaction) == 0x100);
}
