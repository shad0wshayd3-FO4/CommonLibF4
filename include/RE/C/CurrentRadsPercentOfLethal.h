#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class CurrentRadsPercentOfLethal :
		public BSTValueEvent<float>
	{
	public:
	};
	static_assert(sizeof(CurrentRadsPercentOfLethal) == 0x8);
}
