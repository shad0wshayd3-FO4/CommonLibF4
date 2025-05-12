#pragma once

namespace RE
{
	struct TESEquipEvent
	{
		// members
		NiPointer<TESObjectREFR> actor;         // 00
		std::uint32_t            baseObject;    // 08
		std::uint32_t            originalRefr;  // 0C
		std::uint16_t            uniqueID;      // 10
		bool                     equipped;      // 12
	};
	static_assert(sizeof(TESEquipEvent) == 0x18);
}
