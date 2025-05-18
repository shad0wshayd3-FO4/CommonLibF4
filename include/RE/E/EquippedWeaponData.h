#pragma once

#include "RE/B/BGSObjectInstance.h"
#include "RE/B/BSSoundHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTTuple.h"
#include "RE/E/EquippedItemData.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	enum class ATTACK_STATE_ENUM;
	class AimModel;
	class BSCloneReserver;
	class MuzzleFlash;
	class NiAVObject;
	class QueuedFile;

	class __declspec(novtable) EquippedWeaponData :
		public EquippedItemData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::EquippedWeaponData };
		static constexpr auto VTABLE{ VTABLE::EquippedWeaponData };

		void SetupFireSounds(Actor& a_actor, BGSObjectInstanceT<TESObjectWEAP>& a_weapon)
		{
			using func_t = decltype(&EquippedWeaponData::SetupFireSounds);
			static REL::Relocation<func_t> func{ ID::EquippedWeaponData::SetupFireSounds };
			return func(this, a_actor, a_weapon);
		}

		// members
		TESAmmo*                                 ammo;                     // 10
		std::uint32_t                            ammoCount;                // 18
		AimModel*                                aimModel;                 // 20
		MuzzleFlash*                             muzzleFlash;              // 28
		NiAVObject*                              fireNode;                 // 30
		ATTACK_STATE_ENUM                        attackState;              // 38
		BSTArray<BSTTuple<std::uint32_t, void*>> fireLocations;            // 40 - AnimationStanceFireLocationData<NiPoint3>
		NiPointer<QueuedFile>                    weaponPreload;            // 58
		NiPointer<QueuedFile>                    projectilePreload;        // 60
		NiPointer<BSCloneReserver>               reserveProjectileClones;  // 68
		BSSoundHandle                            idleSound;                // 70
		BSSoundHandle                            attackSound;              // 78
		BSSoundHandle                            reverbSound;              // 80
		BSSoundHandle                            prevAttack;               // 88
		BSSoundHandle                            prevReverb;               // 90
		const BGSSoundKeywordMapping*            attackSoundData;          // 98
		bool                                     reverbSoundIsTail;        // A0
	};
	static_assert(sizeof(EquippedWeaponData) == 0xA8);
}
