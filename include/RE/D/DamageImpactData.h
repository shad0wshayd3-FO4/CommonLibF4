#pragma once

namespace RE
{
	struct DamageImpactData
	{
		// members
		NiPoint3A                       location;  // 00
		NiPoint3A                       normal;    // 10
		NiPoint3A                       velocity;  // 20
		NiPointer<bhkNPCollisionObject> colObj;    // 30
	};
	static_assert(sizeof(DamageImpactData) == 0x40);
}
