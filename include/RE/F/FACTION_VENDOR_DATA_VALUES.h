#pragma once

namespace RE
{
	struct FACTION_VENDOR_DATA_VALUES
	{
	public:
		// members
		std::uint16_t startHour;       // 0
		std::uint16_t endHour;         // 2
		std::uint32_t locationRadius;  // 4
		bool          buysStolen;      // 8
		bool          notBuySell;      // 9
		bool          buysNonStolen;   // A
	};
	static_assert(sizeof(FACTION_VENDOR_DATA_VALUES) == 0xC);
}
