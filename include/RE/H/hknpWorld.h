#pragma once

#include "RE/H/hkReferencedObject.h"

namespace RE
{
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
