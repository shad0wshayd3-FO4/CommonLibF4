#pragma once

namespace RE
{
	struct NPC_DATA
	{
	public:
		// members
		std::int16_t  autoCalcHealth;        // 0
		std::int16_t  autoCalcActionPoints;  // 2
		std::uint16_t farDistance;           // 4
		std::int8_t   gearedUpWeapons;       // 6
	};
	static_assert(sizeof(NPC_DATA) == 0x8);
}
