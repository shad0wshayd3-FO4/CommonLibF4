#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class PlayerCommandTypeEvent :
		public BSTValueEvent<COMMAND_TYPE>  // 0
	{
	public:
	};
	static_assert(sizeof(PlayerCommandTypeEvent) == 0x8);
}
