#pragma once

namespace RE
{
	enum class BIPED_OBJECT
	{
		kNone = static_cast<std::underlying_type_t<BIPED_OBJECT>>(-1),
		kHairTop = 0,
		kHairLong = 1,
		kFaceGenHead = 2,
		kBody = 3,
		kLeftHand = 4,
		kRightHand = 5,
		kUnderTorso = 6,
		kUnderLeftArm = 7,
		kUnderRightArm = 8,
		kUnderLeftLeg = 9,
		kUnderRightLeg = 10,
		kAboveTorso = 11,
		kAboveLeftArm = 12,
		kAboveRightArm = 13,
		kAboveLeftLeg = 14,
		kAboveRightLeg = 15,
		kHeadband = 16,
		kEyes = 17,
		kBeard = 18,
		kMouth = 19,
		kNeck = 20,
		kRing = 21,
		kScalp = 22,
		kDecapitation = 23,
		kUnnamed1 = 24,
		kUnnamed2 = 25,
		kUnnamed3 = 26,
		kUnnamed4 = 27,
		kUnnamed5 = 28,
		kShield = 29,
		kPipboy = 30,
		kFX = 31,

		kEditorTotal = 32,

		kWeaponHand = kEditorTotal,
		kWeaponSword = 33,
		kWeaponDagger = 34,
		kWeaponAxe = 35,
		kWeaponMace = 36,
		kWeaponTwoHandMelee = 37,
		kWeaponBow = 38,
		kWeaponStaff = 39,
		kQuiver = 40,
		kWeaponGun = 41,
		kWeaponGrenade = 42,
		kWeaponMine = 43,

		kTotal = 44
	};
}
