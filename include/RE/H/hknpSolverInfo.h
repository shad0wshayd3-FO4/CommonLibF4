#pragma once

#include "RE/H/hkSimdFloat32.h"
#include "RE/H/hkVector4f.h"

namespace RE
{
	class hknpSolverInfo
	{
	public:
		// members
		float         tau;                                   // 000
		float         frictionTau;                           // 004
		hkSimdFloat32 damping;                               // 010
		hkSimdFloat32 deltaTime;                             // 020
		hkSimdFloat32 invDeltaTime;                          // 030
		hkSimdFloat32 subStepDeltaTime;                      // 040
		hkSimdFloat32 subStepInvDeltaTime;                   // 050
		hkSimdFloat32 distanceToLinearTim;                   // 060
		hkSimdFloat32 linearTimToDistance;                   // 070
		hkSimdFloat32 collisionTolerance;                    // 080
		hkSimdFloat32 unitScale;                             // 090
		hkSimdFloat32 collisionAccuracy;                     // 0A0
		float         maxApproachSpeedForHighQualitySolver;  // 0B0
		std::int32_t  numSteps;                              // 0B4
		float         invNumSteps;                           // 0B8
		std::int32_t  numMicroSteps;                         // 0BC
		float         invNumMicroSteps;                      // 0C0
		float         nominalGravityLength;                  // 0C4
		float         expectedDeltaTime;                     // 0C8
		std::uint32_t stepSolveCount;                        // 0CC
		hkVector4f    globalAccelerationPerSubStep;          // 0D0
		hkVector4f    globalAccelerationPerStep;             // 0E0
		hkVector4f    integrateVelocityFactor;               // 0F0
		hkVector4f    invIntegrateVelocityFactor;            // 100
		hkSimdFloat32 rhsFactor;                             // 110
		hkSimdFloat32 frictionRhsFactor;                     // 120
		float         dampDivTau;                            // 130
		float         tauDivDamp;                            // 134
		float         dampDivFrictionTau;                    // 138
		float         frictionTauDivDamp;                    // 13C
	};
	static_assert(sizeof(hknpSolverInfo) == 0x140);
}
