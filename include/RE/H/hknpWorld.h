#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkBitField.h"
#include "RE/H/hkBlockStream.h"
#include "RE/H/hkBool.h"
#include "RE/H/hkEnum.h"
#include "RE/H/hkIntSpaceUtil.h"
#include "RE/H/hkRefPtr.h"
#include "RE/H/hkSimdFloat32.h"
#include "RE/H/hkVector4f.h"
#include "RE/H/hknpBodyManager.h"
#include "RE/H/hknpConstraintManager.h"
#include "RE/H/hknpContactSolverType.h"
#include "RE/H/hknpMotionManager.h"
#include "RE/H/hknpShapeManager.h"
#include "RE/H/hknpSolverInfo.h"
#include "RE/H/hknpThreadSafetyCheck.h"
#include "RE/H/hknpWorldSignals.h"
#include "RE/H/hkReferencedObject.h"
#include "RE/H/hknpWorldCinfo.h"

namespace RE
{
	class hkBlockStreamAllocator;
	class hknpActionManager;
	class hknpBodyQualityLibrary;
	class hknpBroadPhase;
	class hknpCollisionCacheManager;
	class hknpCollisionDispatcher;
	class hknpCollisionQueryDispatcherBase;
	class hknpConstraintAtomSolver;
	class hknpContactConstraintSolver;
	class hknpDeactivationManager;
	class hknpEventDispatcher;
	class hknpInternalCommandProcessor;
	class hknpMaterialLibrary;
	class hknpModifierManager;
	class hknpMotionPropertiesLibrary;
	class hknpNullShapeTagCodec;
	class hknpPostCollideTask;
	class hknpPostSolveTask;
	class hknpShapeTagCodec;
	class hknpSimulation;
	class hknpSimulationContext;
	class hknpSolverSumVelocity;
	class hknpSolverVelocity;
	class hknpSpaceSplitter;
	class hkPrimaryCommandDispatcher;
	class hkSecondaryCommandDispatcher;

	class hknpWorld :
		public hkReferencedObject
	{
	public:
		enum class AdditionMode : std::int32_t;
		enum class SimulationStage : std::int32_t;

		// members
		hknpBodyManager                                                 bodyManager;                       // 010
		hknpMotionManager                                               motionManager;                     // 0D8
		hknpConstraintManager                                           constraintManager;                 // 120
		hknpModifierManager*                                            modifierManager;                   // 150
		hkRefPtr<hkBlockStreamAllocator>                                persistentStreamAllocator;         // 158
		hkBlockStreamAllocator*                                         stepLocalStreamAllocator;          // 160
		hknpSimulation*                                                 simulation;                        // 168
		hknpSpaceSplitter*                                              spaceSplitter;                     // 170
		hknpBroadPhase*                                                 broadPhase;                        // 178
		hkIntSpaceUtil                                                  intSpaceUtil;                      // 180
		hkSimdFloat32                                                   collisionTolerance;                // 1E0
		hknpCollisionCacheManager*                                      collisionCacheManager;             // 1F0
		hknpCollisionDispatcher*                                        collisionDispatcher;               // 1F8
		hknpCollisionQueryDispatcherBase*                               collisionQueryDispatcher;          // 200
		hkBool                                                          contactCachingEnabled;             // 208
		hkBlockStream<std::int8_t>                                      lastFrameContactData;              // 210
		hknpContactSolverType::Enum                                     contactSolverType;                 // 310
		hknpContactConstraintSolver*                                    contactSolver;                     // 318
		hknpConstraintAtomSolver*                                       constraintAtomSolver;              // 320
		hknpSolverInfo                                                  solverInfo;                        // 330
		hkBool                                                          enableSolverDynamicScheduling;     // 470
		hkArray<hknpSolverVelocity>                                     solverVelocities;                  // 478
		hkArray<hknpSolverSumVelocity>                                  solverSumVelocities;               // 488
		hkBool                                                          deactivationEnabled;               // 498
		hknpDeactivationManager*                                        deactivationManager;               // 4A0
		hkBool                                                          deleteCachesOnDeactivation;        // 4A8
		hknpWorldSignals                                                signals;                           // 4B0
		hkPrimaryCommandDispatcher*                                     commandDispatcher;                 // 598
		hkRefPtr<hkSecondaryCommandDispatcher>                          traceDispatcher;                   // 5A0
		std::uint16_t                                                   userData;                          // 5A8
		hkVector4f                                                      gravity;                           // 5B0
		hkRefPtr<hkReferencedObject>                                    defaultModifierSet;                // 5C0
		hkRefPtr<hknpMaterialLibrary>                                   materialLibrary;                   // 5C8
		hkRefPtr<hknpMotionPropertiesLibrary>                           motionPropertiesLibrary;           // 5D0
		hkRefPtr<hknpBodyQualityLibrary>                                qualityLibrary;                    // 5D8
		hkBitField                                                      dirtyMaterials;                    // 5E0
		hkBitField                                                      dirtyQualities;                    // 5F8
		hknpShapeManager                                                shapeManager;                      // 610
		hkRefPtr<hknpShapeTagCodec>                                     shapeTagCodec;                     // 638
		hknpNullShapeTagCodec*                                          nullShapeTagCodec;                 // 640
		hkRefPtr<hknpEventDispatcher>                                   eventDispatcher;                   // 648
		hkRefPtr<hknpInternalCommandProcessor>                          internalPhysicsCommandDispatcher;  // 650
		hkBool                                                          consistencyChecksEnabled;          // 658
		hknpPostCollideTask*                                            postCollideTask;                   // 660
		hknpPostSolveTask*                                              postSolveTask;                     // 668
		hkEnum<SimulationStage, std::uint32_t>                          simulationStage;                   // 670
		hknpSimulationContext*                                          simulationContext;                 // 678
		hknpActionManager*                                              actionManager;                     // 680
		hkEnum<hknpWorldCinfo::SimulationType, std::uint8_t>            simulationType;                    // 688
		hkBool                                                          mergeEventsBeforeDispatch;         // 689
		hkEnum<hknpWorldCinfo::LeavingBroadPhaseBehavior, std::uint8_t> leavingBroadPhaseBehavior;         // 68A
		hknpThreadSafetyCheck                                           threadSafetyCheck;                 // 690
	};
	static_assert(sizeof(hknpWorld) == 0x6D0);
}
