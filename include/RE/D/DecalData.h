#pragma once

namespace RE
{
	class DecalData
	{
	public:
		// members
		DECAL_DATA_DATA data;  // 00
	};
	static_assert(sizeof(DecalData) == 0x24);
}
