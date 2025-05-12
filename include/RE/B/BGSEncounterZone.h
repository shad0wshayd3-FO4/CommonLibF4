#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) BGSEncounterZone :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSEncounterZone };
		static constexpr auto VTABLE{ VTABLE::BGSEncounterZone };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kECZN };

		[[nodiscard]] bool NeverResets() const noexcept { return data.flags.all(ENCOUNTER_ZONE_DATA::FLAG::kNeverReset); }
		[[nodiscard]] bool IsWorkshop() const noexcept { return data.flags.all(ENCOUNTER_ZONE_DATA::FLAG::kWorkshopZone); }

		void SetDetachTime(std::uint32_t a_time)
		{
			gameData.detachTime = a_time;
			AddChange(CHANGE_TYPE::kEncounterZoneGameData);
		}

		// members
		ENCOUNTER_ZONE_DATA      data;      // 20
		ENCOUNTER_ZONE_GAME_DATA gameData;  // 38
	};
	static_assert(sizeof(BGSEncounterZone) == 0x48);
}
