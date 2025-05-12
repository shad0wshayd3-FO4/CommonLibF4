#pragma once

namespace RE
{
	struct BGSProjectileData
	{
	public:
		// members
		std::uint32_t           flags;                // 00
		float                   gravity;              // 04
		float                   speed;                // 08
		float                   range;                // 0C
		TESObjectLIGH*          light;                // 10
		TESObjectLIGH*          muzzleFlashLight;     // 18
		float                   explosionProximity;   // 20
		float                   explosionTimer;       // 24
		BGSExplosion*           explosionType;        // 28
		BGSSoundDescriptorForm* activeSoundLoop;      // 30
		float                   muzzleFlashDuration;  // 38
		float                   fadeOutTime;          // 3C
		float                   force;                // 40
		BGSSoundDescriptorForm* countdownSound;       // 48
		BGSSoundDescriptorForm* deactivateSound;      // 50
		TESObjectWEAP*          defaultWeaponSource;  // 58
		float                   coneSpread;           // 60
		float                   collisionRadius;      // 64
		float                   lifetime;             // 68
		float                   relaunchInterval;     // 6C
		BGSTextureSet*          decalData;            // 70
		BGSCollisionLayer*      collisionLayer;       // 78
		BGSProjectile*          vatsProjectile;       // 80
		std::int8_t             tracerFrequency;      // 88
	};
	static_assert(sizeof(BGSProjectileData) == 0x90);
}
