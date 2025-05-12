#pragma once

namespace RE
{
	struct EquipSlotData
	{
	public:
		// members
		BGSEquipSlot* equipSlot;      // 00
		BSFixedString equipSlotNode;  // 08
	};
	static_assert(sizeof(EquipSlotData) == 0x10);
}
