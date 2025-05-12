#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class CurrentRadsDisplayMagnitude :
		public BSTValueEvent<float>
	{
	public:
	};
	static_assert(sizeof(CurrentRadsDisplayMagnitude) == 0x8);
}
