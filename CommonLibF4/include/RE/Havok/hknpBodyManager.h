#pragma once

#include "RE/Havok/hkArray.h"
#include "RE/Havok/hkBaseTypes.h"
#include "RE/Havok/hkMap.h"
#include "RE/Havok/hknpBodyId.h"

namespace RE
{
	class hkAabb16;
	class hknpBody;
	class hknpMotionManager;
	class hknpWorld;
	class hkStringPtr;

	class hknpBodyManager
	{
	public:
		struct PropertyBuffer;
		struct ScheduledBodyChange;

		// members
		hknpWorld*                            world;
		hknpMotionManager*                    motionManager;
		hkArray<hknpBody>                     bodies;
		hkBool                                bodyBufferIsUserOwned;
		hknpBodyId                            firstFreeBodyId;
		hkArray<hkAabb16>                     previousAabbs;
		hkArray<hkStringPtr>                  bodyNames;
		hkMap<std::uint32_t, PropertyBuffer*> propertyMap;
		std::uint32_t                         numAllocatedBodies;
		std::uint32_t                         numMarkedBodies;
		std::uint32_t                         peakBodyIndex;
		hkArray<hknpBodyId>                   activeBodyIds;
		hkArray<std::uint8_t>                 bodyIdToCellIndexMap;
		hkArray<ScheduledBodyChange>          scheduledBodyChanges;
		hkArray<std::uint32_t>                scheduledBodyChangeIndices;
		hkArray<hknpBodyId>                   bodiesToAddAsActive;
		hkArray<hknpBodyId>                   bodiesToAddAsInctive;
	};
	static_assert(sizeof(hknpBodyManager) == 0xC8);
}
