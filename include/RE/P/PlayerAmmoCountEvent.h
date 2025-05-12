#pragma once

namespace RE
{
	class PlayerAmmoCountEvent :
		public BSTValueEvent<PlayerAmmoCounts>
	{
	public:
	};
	static_assert(sizeof(PlayerAmmoCountEvent) == 0xC);
}
