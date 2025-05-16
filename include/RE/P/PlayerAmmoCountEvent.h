#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/P/PlayerAmmoCounts.h"

namespace RE
{
	class PlayerAmmoCountEvent :
		public BSTValueEvent<PlayerAmmoCounts>
	{
	public:
	};
	static_assert(sizeof(PlayerAmmoCountEvent) == 0xC);
}
