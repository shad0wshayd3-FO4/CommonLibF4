#pragma once

namespace RE
{
	struct PlayerAmmoCounts
	{
	public:
		// members
		std::uint32_t clipAmmo;     // 00
		std::uint32_t reserveAmmo;  // 04
	};
	static_assert(sizeof(PlayerAmmoCounts) == 0x8);
}
