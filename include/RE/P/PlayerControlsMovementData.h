#pragma once

#include "RE/M/MovementData.h"

namespace RE
{
	struct PlayerControlsMovementData :
		public MovementData  // 00
	{
	public:
		// members
		NiPoint3A targetAngle;  // 30
	};
	static_assert(sizeof(PlayerControlsMovementData) == 0x40);
}
