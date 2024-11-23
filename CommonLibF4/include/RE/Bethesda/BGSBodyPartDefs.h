#pragma once

#include "RE/Bethesda/BSFixedString.h"

namespace RE::BGSBodyPartDefs
{
	enum class LIMB_ENUM : std::uint32_t
	{
		kNone = 0xFFFFFFFF,
		kTorso = 0x0,
		kHead1 = 0x1,
		kEye1 = 0x2,
		kLookAt1 = 0x3,
		kFlyGrab = 0x4,
		kHead2 = 0x5,
		kLeftArm1 = 0x6,
		kLeftArm2 = 0x7,
		kRightArm1 = 0x8,
		kRightArm2 = 0x9,
		kLeftLeg1 = 0xA,
		kLeftLeg2 = 0xB,
		kLeftLeg3 = 0xC,
		kRightLeg1 = 0xD,
		kRightLeg2 = 0xE,
		kRightLeg3 = 0xF,
		kBrain = 0x10,
		kWeapon = 0x11,
		kRoot = 0x12,
		kCom = 0x13,
		kPelvis = 0x14,
		kCamera = 0x15,
		kOffsetRoot = 0x16,
		kLeftFoot = 0x17,
		kRightFoot = 0x18,
		kFaceTargetSource = 0x19
	};

	enum class CAUSE_OF_DEATH : std::uint32_t
	{
		kCauseOfDeathNone = 0xFFFFFFFF,
		kCauseOfDeathExplosion = 0x0,
		kCauseOfDeathGun = 0x1,
		kCauseOfDeathBluntWeapon = 0x2,
		kCauseOfDeathHandToHand = 0x3,
		kCauseOfDeathObjectImpact = 0x4,
		kCauseOfDeathPoison = 0x5,
		kCauseOfDeathDecapitation = 0x6
	};

	struct HitReactionData
	{
	public:
		// members
		BSFixedString chainStart;  // 00
		BSFixedString chainEnd;    // 08
		BSFixedString variableX;   // 10
		BSFixedString variableY;   // 18
		BSFixedString variableZ;   // 20
	};
	static_assert(sizeof(HitReactionData) == 0x28);
}
