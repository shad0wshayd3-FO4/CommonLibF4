#pragma once

#include "RE/Havok/hkBaseTypes.h"
#include "RE/Havok/hkBitField.h"
#include "RE/Havok/hkBlockStream.h"
#include "RE/Havok/hkIntSpaceUtil.h"
#include "RE/Havok/hkRefPtr.h"
#include "RE/Havok/hkReferencedObject.h"
#include "RE/Havok/hkSimdFloat.h"
#include "RE/Havok/hkcdRay.h"
#include "RE/Havok/hknpBodyManager.h"
#include "RE/Havok/hknpConstraintManager.h"
#include "RE/Havok/hknpContactSolver.h"
#include "RE/Havok/hknpMotionManager.h"
#include "RE/Havok/hknpShapeManager.h"
#include "RE/Havok/hknpSolverInfo.h"
#include "RE/Havok/hknpThreadSafetyCheck.h"
#include "RE/Havok/hknpWorldSignals.h"

namespace RE
{
	class hkBlockStreamAllocator;
	class hknpActionManager;
	class hknpBodyQualityLibrary;
	class hknpBroadPhase;
	class hknpBroadPhaseConfig;
	class hknpCollisionCacheManager;
	class hknpCollisionDispatcher;
	class hknpCollisionFilter;
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

	class __declspec(novtable) hknpWorld :
		public hkReferencedObject
	{
	public:
		static constexpr auto RTTI{ RTTI::hknpWorld };
		static constexpr auto VTABLE{ VTABLE::hknpWorld };

		enum class AdditionMode : std::int32_t
		{
			kDoNotAddBody = 0,
			kAddBodyNow = 1,
			kAddBodyInNextStep = 2
		};

		enum class SimulationStage : std::int32_t
		{
			kDone = 0x1,
			kPreCollide = 0x2,
			kCollide = 0x4,
			kPostCollide = 0x8,
			kPreSolve = 0x10,
			kSolve = 0x20,
			kPostSolve = 0x40,
		};

		using AdditionFlagsEnum = hkcdRayQueryFlags::Enum;
		using LeavingBroadPhaseBehavior = hknpWorldCinfo::LeavingBroadPhaseBehavior;
		using SimulationType = hknpWorldCinfo::SimulationType;

		void AddBodies(hknpBodyId* a_ids, std::uint32_t a_idCount, AdditionMode a_additionMode, hkFlags<AdditionFlagsEnum, std::uint8_t> a_additionFlags)
		{
			using func_t = decltype(&hknpWorld::AddBodies);
			static REL::Relocation<func_t> func{ REL::ID(2255681) };
			func(this, a_ids, a_idCount, a_additionMode, a_additionFlags);
		}

		hknpBodyId& CreateBody(hknpBodyId& a_id, const hknpBodyCinfo& a_cInfo, AdditionMode a_additionMode, hkFlags<AdditionFlagsEnum, std::uint8_t> a_additionFlags)
		{
			using func_t = decltype(&hknpWorld::CreateBody);
			static REL::Relocation<func_t> func{ REL::ID(2255680) };
			return func(this, a_id, a_cInfo, a_additionMode, a_additionFlags);
		}

		hknpMotionId& CreateMotion(hknpMotionId& a_id, const hknpMotionCinfo& a_cInfo)
		{
			using func_t = decltype(&hknpWorld::CreateMotion);
			static REL::Relocation<func_t> func{ REL::ID(2255688) };
			return func(this, a_id, a_cInfo);
		}

		// members
		hknpBodyManager                                 bodyManager;
		hknpMotionManager                               motionManager;
		hknpConstraintManager                           contraintManager;
		hknpModifierManager*                            modifierManager;
		hkRefPtr<hkBlockStreamAllocator>                persistentStreamAllocator;
		hkBlockStreamAllocator*                         stepLocalStreamAllocator;
		hknpSimulation*                                 simulation;
		hknpSpaceSplitter*                              spaceSplitter;
		hknpBroadPhase*                                 broadPhase;
		hkIntSpaceUtil                                  intSpaceUtil;
		hkSimdFloat32                                   collisionTolerance;
		hknpCollisionCacheManager*                      collisionCacheManager;
		hknpCollisionDispatcher*                        collisionDispatcher;
		hknpCollisionQueryDispatcherBase*               collisionQueryDispatcher;
		hkBool                                          contactCachingEnabled;
		hkBlockStream<char>                             lastFrameContactData;
		hknpContactSolverType::Enum                     contactSolverType;
		hknpContactConstraintSolver*                    contactSolver;
		hknpConstraintAtomSolver*                       constraintAtomSolver;
		hknpSolverInfo                                  solverInfo;
		hkBool                                          enableSolverDynamicScheduling;
		hkArray<hknpSolverVelocity>                     solverVelocities;
		hkArray<hknpSolverSumVelocity>                  solverSumVelocities;
		hkBool                                          deactivationEnabled;
		hknpDeactivationManager*                        deactivationManager;
		hkBool                                          deleteCachesOnDeactivation;
		hknpWorldSignals                                signals;
		hkPrimaryCommandDispatcher*                     commandDispatcher;
		hkRefPtr<hkSecondaryCommandDispatcher>          traceDispatcher;
		std::uint64_t                                   userData;
		hkVector4f                                      gravity;
		hkRefPtr<hkReferencedObject>                    defaultModifierSet;
		hkRefPtr<hknpMaterialLibrary>                   materialLibrary;
		hkRefPtr<hknpMotionPropertiesLibrary>           motionPropertiesLibrary;
		hkRefPtr<hknpBodyQualityLibrary>                qualityLibrary;
		hkBitField                                      dirtyMaterials;
		hkBitField                                      dirtyQualities;
		hknpShapeManager                                shapeManager;
		hkRefPtr<hknpShapeTagCodec>                     shapeTagCodec;
		hknpNullShapeTagCodec*                          nullShapeTagCodec;
		hkRefPtr<hknpEventDispatcher>                   eventDispatcher;
		hkRefPtr<hknpInternalCommandProcessor>          internalPhysicsCommandDispatcher;
		hkBool                                          consistencyChecksEnabled;
		hknpPostCollideTask*                            postCollideTask;
		hknpPostSolveTask*                              postSolveTask;
		hkEnum<SimulationStage, std::uint32_t>          simulationStage;
		hknpSimulationContext*                          simulationContext;
		hknpActionManager*                              actionManager;
		hkEnum<SimulationType, std::uint8_t>            simulationType;
		hkBool                                          mergeEventsBeforeDispatch;
		hkEnum<LeavingBroadPhaseBehavior, std::uint8_t> leavingBroadPhaseBehavior;
		hknpThreadSafetyCheck                           threadSafetyCheck;
	};
	static_assert(sizeof(hknpWorld) == 0x6D0);
}
