#pragma once

#include "RE/H/hkReferencedObject.h"

namespace RE
{
	class hknpCharacterState :
		public hkReferencedObject
	{
	public:
		enum class hknpCharacterStateType
		{
			kOnGround = 0x0,
			kJumping = 0x1,
			kInAir = 0x2,
			kClimbing = 0x3,
			kFlying = 0x4,
			kUserState0 = 0x5,
			kUserState1 = 0x6,
			kUserState2 = 0x7,
			kUserState3 = 0x8,
			kUserState4 = 0x9,
			kUserState5 = 0xA,
			kMaxStateID = 0xB
		};
	};
	static_assert(sizeof(hknpCharacterState) == 0x10);
}
