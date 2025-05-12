#pragma once

#include "RE/E/EquippedItemData.h"

namespace RE
{
	class __declspec(novtable) EquippedWeaponData :
		public EquippedItemData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::EquippedWeaponData };
		static constexpr auto VTABLE{ VTABLE::EquippedWeaponData };

		void SetupFireSounds(Actor& a_actor, BGSObjectInstanceT<TESObjectWEAP>& a_weapon)
		{
			using func_t = decltype(&EquippedWeaponData::SetupFireSounds);
			static REL::Relocation<func_t> func{ REL::ID(2232275) };
			return func(this, a_actor, a_weapon);
		}

		// members
		TESAmmo*                                                                     ammo;                     // 10
		std::uint32_t                                                                ammoCount;                // 18
		AimModel*                                                                    aimModel;                 // 20
		MuzzleFlash*                                                                 muzzleFlash;              // 28
		NiAVObject*                                                                  fireNode;                 // 30
		ATTACK_STATE_ENUM                                                            attackState;              // 38
		BSTArray<BSTTuple<std::uint32_t, AnimationStanceFireLocationData<NiPoint3>>> fireLocations;            // 40
		NiPointer<QueuedFile>                                                        weaponPreload;            // 58
		NiPointer<QueuedFile>                                                        projectilePreload;        // 60
		NiPointer<BSCloneReserver>                                                   reserveProjectileClones;  // 68
		BSSoundHandle                                                                idleSound;                // 70
		BSSoundHandle                                                                attackSound;              // 78
		BSSoundHandle                                                                reverbSound;              // 80
		BSSoundHandle                                                                prevAttack;               // 88
		BSSoundHandle                                                                prevReverb;               // 90
		const BGSSoundKeywordMapping*                                                attackSoundData;          // 98
		bool                                                                         reverbSoundIsTail;        // A0
	};
	static_assert(sizeof(EquippedWeaponData) == 0xA8);
}
