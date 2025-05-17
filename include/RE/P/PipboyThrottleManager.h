#pragma once

#include "RE/B/BSTHashMap.h"
#include "RE/I/IPipboyThrottledValue.h"

namespace RE
{
	class PipboyThrottleManager
	{
	public:
		BSTHashMap<std::uint32_t, IPipboyThrottledValue*> valueMap;  // 00
	};
	static_assert(sizeof(PipboyThrottleManager) == 0x30);
}
