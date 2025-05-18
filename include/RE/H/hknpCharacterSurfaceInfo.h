#pragma once

#include "RE/H/hkBool.h"
#include "RE/H/hkEnum.h"
#include "RE/H/hkVector4f.h"

namespace RE
{
	class hknpCharacterSurfaceInfo
	{
	public:
		enum class SupportedState;

		// members
		hkBool                               isSurfaceDynamic;       // 00
		hkEnum<SupportedState, std::uint8_t> supportedState;         // 01
		std::byte                            pad02[0x02];            // 02
		float                                surfaceDistanceExcess;  // 04
		std::byte                            pad08[8];               // 08
		hkVector4f                           surfaceNormal;          // 10
		hkVector4f                           surfaceVelocity;        // 20
	};
	static_assert(sizeof(hknpCharacterSurfaceInfo) == 0x30);
}
