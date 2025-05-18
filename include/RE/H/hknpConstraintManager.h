#pragma once

#include "RE/H/hkBool.h"
#include "RE/H/hkHandle.h"
#include "RE/H/hknpConstraintIdDiscriminant.h"

namespace RE
{
	class hknpConstraint;
	class hknpWorld;

	class hknpConstraintManager
	{
	public:
		// members
		hknpWorld*                                                        world;                        // 00
		hknpConstraint*                                                   constraintBuffer;             // 08
		std::uint32_t                                                     capacity;                     // 10
		hkBool                                                            constraintBufferIsUserOwned;  // 14
		hkHandle<std::uint32_t, 2147483647, hknpConstraintIdDiscriminant> firstDestroyedConstraintId;   // 18
		hkHandle<std::uint32_t, 2147483647, hknpConstraintIdDiscriminant> firstFreeConstraintId;        // 1C
		std::uint32_t                                                     numAllocatedConstraints;      // 20
		std::uint32_t                                                     numDestroyedConstraints;      // 24
		hkHandle<std::uint32_t, 2147483647, hknpConstraintIdDiscriminant> peakConstraintId;             // 28
	};
	static_assert(sizeof(hknpConstraintManager) == 0x30);
}
