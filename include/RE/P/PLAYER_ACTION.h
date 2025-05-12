#pragma once

namespace RE
{
	enum class PLAYER_ACTION
	{
		kNone = 0x0,
		kSwingMeleeWeapon = 0x1,
		kCastProjectileSpell = 0x2,
		kShootBow = 0x3,
		kZKeyObject = 0x4,
		kJumping = 0x5,
		kKnockingOverObjects = 0x6,
		kStandOnTableChair = 0x7,
		kIronSights = 0x8,
		kDestroyObject = 0x9,
		kLockedObject = 0xA,
		kPickpocket = 0xB,
		kCastSelfSpell = 0xC,
		kShout = 0xD,
		kActorCollision = 0xE,
		kInvalidMarker = 0x10,
	};
}
