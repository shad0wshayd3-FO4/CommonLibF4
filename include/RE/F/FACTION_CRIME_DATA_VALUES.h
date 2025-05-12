#pragma once

namespace RE
{
	struct FACTION_CRIME_DATA_VALUES
	{
	public:
		// members
		bool          arrest;               // 00
		bool          attackOnSight;        // 01
		std::uint16_t murderCrimeGold;      // 02
		std::uint16_t assaultCrimeGold;     // 04
		std::uint16_t trespassCrimeGold;    // 06
		std::uint16_t pickpocketCrimeGold;  // 08
		float         stealCrimeGoldMult;   // 0C
		std::uint16_t escapeCrimeGold;      // 10
		std::uint16_t unused;               // 12
	};
	static_assert(sizeof(FACTION_CRIME_DATA_VALUES) == 0x14);
}
