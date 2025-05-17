#pragma once

namespace RE
{
	class ENCOUNTER_ZONE_GAME_DATA
	{
	public:
		// members
		std::uint32_t detachTime;  // 00
		std::uint32_t attachTime;  // 04
		std::uint32_t resetTime;   // 08
		std::uint16_t zoneLevel;   // 0C
	};
	static_assert(sizeof(ENCOUNTER_ZONE_GAME_DATA) == 0x10);
}
