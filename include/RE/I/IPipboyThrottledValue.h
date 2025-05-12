#pragma once

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
}
