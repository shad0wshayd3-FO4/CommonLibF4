#pragma once

#include "RE/D/DECAL_DATA_DATA.h"

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
