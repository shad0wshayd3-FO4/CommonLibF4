#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/P/Projectile.h"
#include "RE/P/ProjectileLaunchData.h"

namespace RE
{
	class BeamProjectileImpactEvent;
	class bhkCollisionQueryResultHandle;
	class BSProceduralGeomEvent;

	class __declspec(novtable) BeamProjectile :
		public Projectile,                                 // 000
		public BSTEventSource<BeamProjectileImpactEvent>,  // 278
		public BSTEventSink<BSProceduralGeomEvent>         // 270
	{
	public:
		static constexpr auto RTTI{ RTTI::BeamProjectile };
		static constexpr auto VTABLE{ VTABLE::BeamProjectile };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kPBEA };

		// members
		ProjectileLaunchData           launchData;       // 2D0
		bhkCollisionQueryResultHandle* castResult;       // 370
		float                          baseModelLength;  // 378
		bool                           transformSet;     // 37C
		bool                           queueUncull;      // 37D
		bool                           dealtDamage;      // 37E
	};
	static_assert(sizeof(BeamProjectile) == 0x380);
}
