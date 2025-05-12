#pragma once

namespace RE
{
	class hknpMotionCinfo
	{
	public:
		hknpMotionCinfo()
		{
			using func_t = void (*)(hknpMotionCinfo*);
			static REL::Relocation<func_t> func{ REL::ID(2258369) };
			func(this);
		}

		void InitializeAsKeyFramed(hknpBodyCinfo* a_cInfos, std::uint32_t a_cInfosNum)
		{
			using func_t = decltype(&hknpMotionCinfo::InitializeAsKeyFramed);
			static REL::Relocation<func_t> func{ REL::ID(2258373) };
			func(this, a_cInfos, a_cInfosNum);
		}

		// members
		hknpMotionPropertiesId motionPropertiesId;
		hkBool                 enableDeactivation;
		float                  inverseMass;
		float                  massFactor;
		float                  maxLinearAccelerationDistancePerStep;
		float                  maxRotationToPreventTunneling;
		hkVector4f             inverseInertiaLocal;
		hkVector4f             centerOfMassWorld;
		hkQuaternionf          orientation;
		hkVector4f             linearVelocity;
		hkVector4f             angularVelocity;
	};
	static_assert(sizeof(hknpMotionCinfo) == 0x70);
}
