#pragma once

namespace RE
{
	enum class CONDITIONITEMOBJECT : unsigned
	{
		kSelf = 0x0,
		kTarget = 0x1,
		kRef = 0x2,
		kCombatTarget = 0x3,
		kLinkedRef = 0x4,
		kQuestAlias = 0x5,
		kPackData = 0x6,
		kEventData = 0x7,
		kCommandTarget = 0x8,
		kEventCameraRef = 0x9,
		kMyKiller = 0xA
	};
}
