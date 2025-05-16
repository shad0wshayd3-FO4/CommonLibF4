#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	class ActiveEffectList
	{
	public:
		// members
		BSTArray<BSTSmartPointer<ActiveEffect>> data;       // 00
		std::int8_t                             iterating;  // 18
	};
	static_assert(sizeof(ActiveEffectList) == 0x20);
}
