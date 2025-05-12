#pragma once

namespace RE
{
	class hknpWorldCinfo
	{
	public:
		enum class SimulationType : std::int32_t
		{
			kSingleThreaded = 0,
			kMultiThreaded = 1,
		};

		enum class LeavingBroadPhaseBehavior : std::int32_t
		{
			kDoNothing = 0x0,
			kRemoveBody = 0x1,
			kFreezeBody = 0x2,
		};

		// members
		std::int32_t                                    bodyBufferCapacity;
		hknpBody*                                       userBodyBuffer;
		std::int32_t                                    motionBufferCapacity;
		hknpMotion*                                     userMotionBuffer;
		std::int32_t                                    constraintBufferCapacity;
		hknpConstraint*                                 userConstraintBuffer;
		hkBlockStreamAllocator*                         persistentStreamAllocator;
		hkRefPtr<hknpMaterialLibrary>                   materialLibrary;
		hkRefPtr<hknpMotionPropertiesLibrary>           motionPropertiesLibrary;
		hkRefPtr<hknpBodyQualityLibrary>                qualityLibrary;
		hkEnum<SimulationType, std::uint8_t>            simulationType;
		std::int32_t                                    numSplitterCells;
		hkVector4f                                      gravity;
		hkBool                                          enableContactCaching;
		hkBool                                          mergeEventsBeforeDispatch;
		hkEnum<LeavingBroadPhaseBehavior, std::uint8_t> leavingBroadPhaseBehavior;
		hkAabb                                          broadPhaseAabb;
		hkRefPtr<hknpBroadPhaseConfig>                  broadPhaseConfig;
		hkRefPtr<hknpCollisionFilter>                   collisionFilter;
		hkRefPtr<hknpShapeTagCodec>                     shapeTagCodec;
		float                                           collisionTolerance;
		float                                           relativeCollisionAccuracy;
		hkBool                                          enableWeldingForDefaultObjects;
		hkBool                                          enableWeldingForCriticalObjects;
		float                                           solverTau;
		float                                           solverDamp;
		std::int32_t                                    solverIterations;
		std::int32_t                                    solverMicrosteps;
		float                                           defaultSolverTimestep;
		float                                           maxApproachSpeedForHighQualitySolver;
		hkBool                                          enableDeactivation;
		hkBool                                          deleteCachesOnDeactivation;
		std::int32_t                                    largeIslandSize;
		hkBool                                          enableSolverDynamicScheduling;
		hknpContactSolverType::Enum                     contactSolverType;
		float                                           unitScale;
		hkBool                                          applyUnitScaleToStaticConstants;
	};
	static_assert(sizeof(hknpWorldCinfo) == 0x100);
}
