#pragma once

namespace RE
{
	struct WORLD_MAP_OFFSET_DATA
	{
	public:
		// members
		float mapScale;    // 00
		float mapOffsetX;  // 04
		float mapOffsetY;  // 08
		float mapOffsetZ;  // 0C
	};
	static_assert(sizeof(WORLD_MAP_OFFSET_DATA) == 0x10);
}
