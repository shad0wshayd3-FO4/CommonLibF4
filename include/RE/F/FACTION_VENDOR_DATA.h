#pragma once

namespace RE
{
	struct FACTION_VENDOR_DATA
	{
	public:
		// members
		FACTION_VENDOR_DATA_VALUES vendorValues;       // 00
		PackageLocation*           vendorLocation;     // 10
		TESCondition*              vendorConditions;   // 18
		BGSListForm*               vendorSellBuyList;  // 20
		TESObjectREFR*             merchantContainer;  // 28
		std::uint32_t              lastDayReset;       // 30
	};
	static_assert(sizeof(FACTION_VENDOR_DATA) == 0x38);
}
