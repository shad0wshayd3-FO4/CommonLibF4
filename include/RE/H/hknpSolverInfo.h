#pragma once

namespace RE
{
	struct hknpSolverInfo
	{
		// members
		float         tau;
		float         frictionTau;
		hkSimdFloat32 damping;
		hkSimdFloat32 deltaTime;
		hkSimdFloat32 invDeltaTime;
		hkSimdFloat32 subStepDeltaTime;
		hkSimdFloat32 subStepInvDeltaTime;
		hkSimdFloat32 distanceToLinearTim;
		hkSimdFloat32 linearTimToDistance;
		hkSimdFloat32 collisionTolerance;
		hkSimdFloat32 unitScale;
		hkSimdFloat32 collisionAccuracy;
		float         maxApproachSpeedForHighQualitySolver;
		std::int32_t  numSteps;
		float         invNumSteps;
		std::int32_t  numMicroSteps;
		float         invNumMicroSteps;
		float         nominalGravityLength;
		float         expectedDeltaTime;
		std::uint32_t stepSolveCount;
		hkVector4f    globalAccelerationPerSubStep;
		hkVector4f    globalAccelerationPerStep;
		hkVector4f    integrateVelocityFactor;
		hkVector4f    invIntegrateVelocityFactor;
		hkSimdFloat32 rhsFactor;
		hkSimdFloat32 frictionRhsFactor;
		float         dampDivTau;
		float         tauDivDamp;
		float         dampDivFrictionTau;
		float         frictionTauDivDamp;
	};
	static_assert(sizeof(hknpSolverInfo) == 0x140);
}
