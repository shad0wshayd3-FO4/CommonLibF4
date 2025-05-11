#pragma once

#include "RE/Havok/hkArray.h"
#include "RE/Havok/hkBaseTypes.h"
#include "RE/Havok/hknpMotionId.h"

namespace RE
{
	class hknpBodyManager;
	class hknpMotion;

	class hknpMotionManager
	{
	public:
		struct CellData;

		// members
		hknpBodyManager*    bodyManager;
		hkArray<hknpMotion> motions;
		hkBool              motionBufferIsUserOwned;
		hknpMotionId        firstFreeMotionId;
		hknpMotionId        firstMarkedMotionId;
		std::uint32_t       numAllocatedMotions;
		std::uint32_t       numMarkedMotions;
		std::uint32_t       peakMotionIndex;
		hkArray<CellData>   activeMotionGrid;
		hkBool              isLocked;
	};
	static_assert(sizeof(hknpMotionManager) == 0x48);
}
