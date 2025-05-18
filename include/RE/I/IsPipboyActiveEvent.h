#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class IsPipboyActiveEvent :
		public BSTValueEvent<bool>  // 00
	{
	public:
	};
	static_assert(sizeof(IsPipboyActiveEvent) == 0x02);
}
