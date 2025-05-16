#pragma once

#include "RE/N/NiPointer.h"
#include "RE/B/BGSObjectInstance.h"
#include "RE/B/BGSEquipIndex.h"

namespace RE
{
	class EquippedItemData;

	class EquippedItem
	{
	public:
		// members
		BGSObjectInstance           item;        // 00
		const BGSEquipSlot*         equipSlot;   // 10
		BGSEquipIndex               equipIndex;  // 18
		NiPointer<EquippedItemData> data;        // 20
	};
	static_assert(sizeof(EquippedItem) == 0x28);
}
