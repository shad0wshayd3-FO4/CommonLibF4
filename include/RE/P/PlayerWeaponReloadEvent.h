#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class PlayerWeaponReloadEvent :
		public BSTValueEvent<bool>
	{
	public:
	};
	static_assert(sizeof(PlayerWeaponReloadEvent) == 0x2);
}
