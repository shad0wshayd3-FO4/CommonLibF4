#pragma once

namespace RE
{
	struct WORLD_MAP_DATA
	{
	public:
		// members
		std::uint32_t usableWidth;   // 00
		std::uint32_t usableHeight;  // 04
		std::int16_t  nwCellX;       // 08
		std::int16_t  nwCellY;       // 0A
		std::int16_t  seCellX;       // 0C
		std::int16_t  seCellY;       // 0E
	};
	static_assert(sizeof(WORLD_MAP_DATA) == 0x10);
}
