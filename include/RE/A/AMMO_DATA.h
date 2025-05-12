#pragma once

namespace RE
{
	struct AMMO_DATA
	{
	public:
		// members
		BGSProjectile* projectile;  // 00
		std::uint32_t  health;      // 08
		std::int8_t    flags;       // 0C
		float          damage;      // 10
	};
	static_assert(sizeof(AMMO_DATA) == 0x18);
}
