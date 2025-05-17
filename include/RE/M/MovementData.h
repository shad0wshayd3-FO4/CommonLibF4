#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	class MovementData
	{
	public:
		// members
		NiPoint3A movementRotation;  // 00
		NiPoint3A rotationSpeed;     // 10
		float     movementSpeed;     // 20
	};
	static_assert(sizeof(MovementData) == 0x30);
}
