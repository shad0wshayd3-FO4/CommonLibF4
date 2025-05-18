#pragma once

#include "RE/H/hkRefPtr.h"
#include "RE/H/hkVector4f.h"
#include "RE/H/hkEnum.h"
#include "RE/H/hkBool.h"
#include "RE/H/hkAabb.h"
#include "RE/H/hknpContactSolverType.h"

namespace RE
{
	class hkBlockStreamAllocator;
	class hknpBody;
	class hknpBodyQualityLibrary;
	class hknpBroadPhaseConfig;
	class hknpCollisionFilter;
	class hknpConstraint;
	class hknpMaterialLibrary;
	class hknpMotion;
	class hknpMotionPropertiesLibrary;
	class hknpShapeTagCodec;

	class hknpWorldCinfo
	{
	public:
		enum class LeavingBroadPhaseBehavior;
		enum class SimulationType;

		// members
		std::int32_t                                    m_bodyBufferCapacity;                    // 00
		hknpBody*                                       m_userBodyBuffer;                        // 08
		std::int32_t                                    m_motionBufferCapacity;                  // 10
		hknpMotion*                                     m_userMotionBuffer;                      // 18
		std::int32_t                                    m_constraintBufferCapacity;              // 20
		hknpConstraint*                                 m_userConstraintBuffer;                  // 28
		hkBlockStreamAllocator*                         m_persistentStreamAllocator;             // 30
		hkRefPtr<hknpMaterialLibrary>                   m_materialLibrary;                       // 38
		hkRefPtr<hknpMotionPropertiesLibrary>           m_motionPropertiesLibrary;               // 40
		hkRefPtr<hknpBodyQualityLibrary>                m_qualityLibrary;                        // 48
		hkEnum<SimulationType, std::uint8_t>            m_simulationType;                        // 50
		std::int32_t                                    m_numSplitterCells;                      // 54
		hkVector4f                                      m_gravity;                               // 60
		hkBool                                          m_enableContactCaching;                  // 70
		hkBool                                          m_mergeEventsBeforeDispatch;             // 71
		hkEnum<LeavingBroadPhaseBehavior, std::uint8_t> m_leavingBroadPhaseBehavior;             // 72
		hkAabb                                          m_broadPhaseAabb;                        // 80
		hkRefPtr<hknpBroadPhaseConfig>                  m_broadPhaseConfig;                      // A0
		hkRefPtr<hknpCollisionFilter>                   m_collisionFilter;                       // A8
		hkRefPtr<hknpShapeTagCodec>                     m_shapeTagCodec;                         // B0
		float                                           m_collisionTolerance;                    // B8
		float                                           m_relativeCollisionAccuracy;             // BC
		hkBool                                          m_enableWeldingForDefaultObjects;        // C0
		hkBool                                          m_enableWeldingForCriticalObjects;       // C1
		float                                           m_solverTau;                             // C4
		float                                           m_solverDamp;                            // C8
		std::int32_t                                    m_solverIterations;                      // CC
		std::int32_t                                    m_solverMicrosteps;                      // D0
		float                                           m_defaultSolverTimestep;                 // D4
		float                                           m_maxApproachSpeedForHighQualitySolver;  // D8
		hkBool                                          m_enableDeactivation;                    // DC
		hkBool                                          m_deleteCachesOnDeactivation;            // DD
		std::int32_t                                    m_largeIslandSize;                       // E0
		hkBool                                          m_enableSolverDynamicScheduling;         // E4
		hknpContactSolverType::Enum                     m_contactSolverType;                     // E8
		float                                           m_unitScale;                             // EC
		hkBool                                          m_applyUnitScaleToStaticConstants;       // F0
	};
	static_assert(sizeof(hknpWorldCinfo) == 0x100);
}
