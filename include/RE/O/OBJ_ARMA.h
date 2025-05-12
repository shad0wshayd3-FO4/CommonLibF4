#pragma once

namespace RE
{
	struct OBJ_ARMA
	{
	public:
		// members
		std::int8_t priorities[2];  // 0
		std::int8_t modelRange[2];  // 2
		std::int8_t unused[2];      // 4
		std::int8_t soundValue;     // 6
		float       weaponAdjust;   // 8
	};
	static_assert(sizeof(OBJ_ARMA) == 0xC);
}
