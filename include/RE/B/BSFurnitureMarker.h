#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	class BSFurnitureMarker
	{
	public:
		// members
		NiPoint3      position;              // 00
		BGSKeyword*   actorMustHaveKeyword;  // 10
		float         heading;               // 18
		std::uint32_t allowedAnimations;     // 1C
	};
	static_assert(sizeof(BSFurnitureMarker) == 0x20);
}
