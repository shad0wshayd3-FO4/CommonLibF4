#pragma once

#include "RE/Havok/hkBaseTypes.h"

namespace RE
{
	enum class hknpCollisionFlagsEnum : std::int32_t
	{
		kIsStatic = 0x1,
		kIsDynamic = 0x2,
		kIsKeyframed = 0x4,
		kIsActive = 0x8,
		kDontCollide = 0x100,
		kDontBuildContactJacobians = 0x200,
		kRaiseTriggerEvents = 0x10,
		kRaiseManifoldStatusEvents = 0x20,
		kRaiseManifoldProcessedEvents = 0x40,
		kRaiseContactImpulseEvents = 0x80,
		kEnableRestitution = 0x100000,
		kEnableTriggerModifier = 0x200000,
		kEnableImpulseClipping = 0x400000,
		kEnableMassChanger = 0x800000,
		kEnableSoftContacts = 0x1000000,
		kEnableSurfaceVelocity = 0x2000000,
		kTempRebuildCollisionCaches = 0x400,
		kTempDropNewCvxCvxCollisions = 0x800,
		kTempBodyOrAABBIsModified = 0x1000,
		kTempRebuildContactCaches = 0x2000,
		kIsNonRuntime = 0x4000,
		kIsBreakable = 0x8000,
		kUserFlag0 = 0x10000,
		kUserFlag1 = 0x20000,
		kUserFlag2 = 0x40000,
		kUserFlag3 = 0x80000,
		kUserFlag4 = 0x4000000,
		kUserFlag5 = 0x8000000,
		kUserFlag6 = 0x10000000,
		kMaskInternalBodyFlags = 0xF,
		kMaskTempFlags = 0x3C00,
		kMaskAutoMaterialFlags = 0x3F00000,
		kMaskAllFlags = static_cast<std::int32_t>(0xFFFFFFFF),
	};

	struct hknpCollisionFlags :
		public hkFlags<hknpCollisionFlagsEnum, std::int32_t>
	{
		using enum hknpCollisionFlagsEnum;
	};
	static_assert(sizeof(hknpCollisionFlags) == 0x4);
}
