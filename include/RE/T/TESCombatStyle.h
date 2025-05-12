#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) TESCombatStyle :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESCombatStyle };
		static constexpr auto VTABLE{ VTABLE::TESCombatStyle };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kCSTY };

		// members
		CombatStyleGeneralData    generalData;     // 20
		CombatStyleMeleeData      meleeData;       // 50
		CombatStyleRangedData     rangedData;      // 78
		CombatStyleCloseRangeData closeRangeData;  // 7C
		CombatStyleLongRangeData  longRangeData;   // A8
		CombatStyleCoverData      coverData;       // BC
		CombatStyleFlightData     flightData;      // C0
		std::uint32_t             flags;           // E0
	};
	static_assert(sizeof(TESCombatStyle) == 0xE8);
}
