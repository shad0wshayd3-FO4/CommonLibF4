#pragma once

#include "RE/H/hkBitField.h"
#include "RE/H/hkArray.h"
#include "RE/H/hkBool.h"
#include "RE/H/hknpBodyId.h"
#include "RE/H/hkMap.h"
#include "RE/H/hkFlags.h"

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
		enum class ScheduledBodyFlagsEnum;

		class BodyIterator
		{
		public:
			// members
			const hknpBodyManager* bodyManager;  // 00
			std::int32_t           bodyIndex;    // 08
		};
		static_assert(sizeof(BodyIterator) == 0x10);

		class PropertyBuffer
		{
		public:
			// members
			std::int32_t bufferSize;    // 00
			std::int32_t propertySize;  // 04
			hkBitField   occupancy;     // 08
			void*        properties;    // 20
		};
		static_assert(sizeof(PropertyBuffer) == 0x28);

		class ScheduledBodyChange
		{
		public:
			// members
			hknpBodyId                                     bodyId;              // 00
			hkFlags<ScheduledBodyFlagsEnum, std::uint16_t> scheduledBodyFlags;  // 04
			std::uint32_t                                  pendingAddIndex;     // 08
		};
		static_assert(sizeof(ScheduledBodyChange) == 0x0C);

		// members
		hknpWorld*                            world;                       // 00
		hknpMotionManager*                    motionManager;               // 08
		hkArray<hknpBody>                     bodies;                      // 10
		hkBool                                bodyBufferIsUserOwned;       // 20
		hknpBodyId                            firstFreeBodyId;             // 24
		hkArray<hkAabb16>                     previousAabbs;               // 28
		hkArray<hkStringPtr>                  bodyNames;                   // 38
		hkMap<std::uint16_t, PropertyBuffer*> propertyMap;                 // 48
		std::uint32_t                         numAllocatedBodies;          // 58
		std::uint32_t                         numMarkedBodies;             // 5C
		std::uint32_t                         peakBodyIndex;               // 60
		hkArray<hknpBodyId>                   activeBodyIds;               // 68
		hkArray<std::uint8_t>                 bodyIdToCellIndexMap;        // 78
		hkArray<ScheduledBodyChange>          scheduledBodyChanges;        // 88
		hkArray<std::uint32_t>                scheduledBodyChangeIndices;  // 98
		hkArray<hknpBodyId>                   bodiesToAddAsActive;         // A8
		hkArray<hknpBodyId>                   bodiesToAddAsInactive;       // B8
	};
	static_assert(sizeof(hknpBodyManager) == 0xC8);
}
