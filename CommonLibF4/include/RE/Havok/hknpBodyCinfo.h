#pragma once

#include "RE/Havok/hknpBody.h"
#include "RE/Havok/hkQuaternion.h"
#include "RE/Havok/hkRefPtr.h"
#include "RE/Havok/hkStringPtr.h"
#include "RE/Havok/hkVector4.h"

namespace RE
{
	class hkLocalFrame;

	class hknpBodyCinfo
	{
	public:
		hknpBodyCinfo()
		{
			using func_t = void(*)(hknpBodyCinfo*);
			static REL::Relocation<func_t> func{ REL::ID(2255967) };
			func(this);
		}

		// members
		const hknpShape*                              shape;
		hknpBodyId                                    reservedBodyId;
		hknpMotionId                                  motionId;
		hknpBodyQualityId                             qualityId;
		hknpMaterialId                                materialId;
		std::uint32_t                                 collisionFilterInfo;
		hknpCollisionFlags                            flags;
		float                                         collisionLookAheadDistance;
		hkStringPtr                                   name;
		std::uint64_t                                 userData;
		hkVector4f                                    position;
		hkQuaternionf                                 orientation;
		hkFlags<hknpBody::SpuFlagsEnum, std::uint8_t> spuFlags;
		hkRefPtr<hkLocalFrame>                        localFrame;
	};
	static_assert(sizeof(hknpBodyCinfo) == 0x60);
}
