#pragma once

#include "RE/Bethesda/BSTHashMap.h"

namespace RE
{
	class IPipboyThrottledValue
	{
	public:
		static constexpr auto RTTI{ RTTI::IPipboyThrottledValue };
		static constexpr auto VTABLE{ VTABLE::IPipboyThrottledValue };

		// members
		virtual ~IPipboyThrottledValue();  // 00

		// add
		void* Update();  // 01
	};
	static_assert(sizeof(IPipboyThrottledValue) == 0x8);

	class PipboyThrottleManager
	{
		BSTHashMap<std::uint32_t, IPipboyThrottledValue*> valueMap;
	};
	static_assert(sizeof(PipboyThrottleManager) == 0x30);
}
