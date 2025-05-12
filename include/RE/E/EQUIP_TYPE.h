#pragma once

namespace RE
{
	enum class EQUIP_TYPE
	{
		kNone = 0x0,
		kEquipped = 0x1,
		kLeftHandEquip = 0x2,
		kRightHandEquip = 0x3,
		kBothHandEquip = 0x4,
		kWillEquipAgain = 0x5
	};
}
