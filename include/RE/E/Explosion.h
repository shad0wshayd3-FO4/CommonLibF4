#pragma once

#include "RE/T/TESObjectREFR.h"

namespace RE
{
	class __declspec(novtable) Explosion :
		public TESObjectREFR  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::Explosion };
		static constexpr auto VTABLE{ VTABLE::Explosion };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kREFR };

		struct ExplodedLimb
		{
		public:
			// members
			REX::EnumSet<BGSBodyPartDefs::LIMB_ENUM, std::int32_t> limb;           // 00
			ActorValueInfo*                                        limbCondition;  // 08
			float                                                  distance;       // 10
		};
		static_assert(sizeof(ExplodedLimb) == 0x18);

		class ExplosionTarget
		{
		public:
			// members
			ObjectRefHandle        ref;                     // 00
			std::uint32_t          flags;                   // 04
			float                  hitFromExplosionSqrLen;  // 08
			BSTArray<ExplodedLimb> limbArray;               // 10
		};
		static_assert(sizeof(ExplosionTarget) == 0x28);

		// add
		virtual void Initialize();           // C6
		virtual void Update(float a_delta);  // C7
		virtual void FindTargets();          // C8

		// members
		hknpClosestUniqueBodyIdHitCollector collector;           // 110
		void*                               explosionDBHandle;   // 520 - TODO
		float                               age;                 // 528
		float                               obj3Dlifetime;       // 52C
		float                               audioLifetime;       // 530
		float                               buildTime;           // 534
		float                               innerRadius;         // 538
		float                               outerRadius;         // 53C
		float                               imageSpaceRadius;    // 540
		float                               damageMult;          // 544
		BSSimpleList<ExplosionTarget*>      targetList;          // 548
		BSTSmallArray<BSSoundHandle, 4>     soundHandles;        // 558
		NiPointer<NiLight>                  light;               // 588
		ObjectRefHandle                     owner;               // 590
		ObjectRefHandle                     explodedRef;         // 594
		ObjectRefHandle                     createdRef;          // 598
		BSTSmartPointer<ActorCause>         actorCause;          // 5A0
		NonActorMagicCaster*                caster;              // 5A8
		BGSObjectInstanceT<TESObjectWEAP>   weaponSource;        // 5B0
		std::int32_t                        frameCount;          // 5C0
		NiPoint3A                           closestPoint;        // 5D0
		NiPoint3A                           closestPointNormal;  // 5E0
		float                               calculatedDamage;    // 5F0
		float                               scale;               // 5F4
		std::uint32_t                       flags;               // 5F8
	};
	static_assert(sizeof(Explosion) == 0x600);
}
