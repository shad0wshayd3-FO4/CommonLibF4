#pragma once

namespace RE
{
	class PipboyThrottleManager
	{
		BSTHashMap<std::uint32_t, IPipboyThrottledValue*> valueMap;
	};
	static_assert(sizeof(PipboyThrottleManager) == 0x30);
}
