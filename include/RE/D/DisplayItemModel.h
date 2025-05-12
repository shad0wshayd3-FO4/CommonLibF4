#pragma once

#include "RE/B/BaseLoadedInventoryModel.h"

namespace RE
{
	struct DisplayItemModel :
		public BaseLoadedInventoryModel  // 00
	{
	public:
		// members
		float         itemRotation;  // 40
		std::uint32_t uniqueIndex;   // 44
		std::uint16_t column;        // 48
		std::uint16_t index;         // 4A
		std::uint16_t row;           // 4C
	};
	static_assert(sizeof(DisplayItemModel) == 0x50);
}
