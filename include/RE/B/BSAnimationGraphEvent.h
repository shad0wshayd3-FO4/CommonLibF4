#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	struct BSAnimationGraphEvent
	{
	public:
		// members
		const std::uint64_t holderID;  // 00
		const BSFixedString tag;       // 08
		const BSFixedString payload;   // 10
	};
	static_assert(sizeof(BSAnimationGraphEvent) == 0x18);
}
