#pragma once

namespace RE
{
	enum class WEAPON_FLAGS : std::uint32_t
	{
		kPlayerOnly = 0x00000001,
		kNPCsUseAmmo = 0x00000002,
		kNoJamAfterReload = 0x00000004,
		kChargingReload = 0x00000008,
		kMinorCrime = 0x00000010,
		kFixedRange = 0x00000020,
		kNotUsedInNormalCombat = 0x00000040,
		kCritEffectOnDeath = 0x00000100,
		kChargingAttack = 0x00000200,
		kHoldInputToPower = 0x00000800,
		kNonHostile = 0x00001000,
		kBoundWeapon = 0x00002000,
		kIgnoresNormalWeaponResistance = 0x00004000,
		kAutomatic = 0x00008000,
		kRepeatableSingleFire = 0x00010000,
		kCantDrop = 0x00020000,
		kHideBackpack = 0x00040000,
		kEmbeddedWeapon = 0x00080000,
		kNotPlayable = 0x00100000,
		kHasScope = 0x00200000,
		kBoltAction = 0x00400000,
		kSecondaryWeapon = 0x00800000,
		kDisableShells = 0x01000000,
	};
}
