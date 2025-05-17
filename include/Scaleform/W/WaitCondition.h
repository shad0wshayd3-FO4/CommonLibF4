#pragma once

namespace Scaleform
{
	class WaitConditionImpl;

	class WaitCondition
	{
	public:
		~WaitCondition() noexcept {}

		// members
		WaitConditionImpl* impl;  // 00
	};
	static_assert(sizeof(WaitCondition) == 0x8);
}
