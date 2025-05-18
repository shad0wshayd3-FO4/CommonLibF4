#pragma once

#include "RE/H/hkReferencedObject.h"

namespace RE
{
	class hknpCharacterState :
		public hkReferencedObject
	{
	public:
		enum class hknpCharacterStateType;
	};
	static_assert(sizeof(hknpCharacterState) == 0x10);
}
