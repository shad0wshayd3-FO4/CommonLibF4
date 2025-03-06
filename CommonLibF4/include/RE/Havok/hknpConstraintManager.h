#pragma once

#include "RE/Havok/hkArray.h"
#include "RE/Havok/hkBaseTypes.h"
#include "RE/Havok/hknpConstraintId.h"

namespace RE
{
	class hknpConstraint;

	class hknpConstraintManager
	{
	public:
		// members
		hknpWorld*       world;
		hknpConstraint*  constraintBuffer;
		std::uint32_t    capacity;
		hkBool           constraintBufferIsUserOwned;
		hknpConstraintId firstDestroyedConstraintId;
		hknpConstraintId firstFreeConstraintId;
		std::uint32_t    numAllocatedConstraints;
		std::uint32_t    numDestroyedConstraints;
		hknpConstraintId peakConstraintId;
	};
	static_assert(sizeof(hknpConstraintManager) == 0x30);
}
