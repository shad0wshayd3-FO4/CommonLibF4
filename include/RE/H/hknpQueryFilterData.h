#pragma once

#include "RE/H/hkPadSpu.h"
#include "RE/H/hknpMaterialId.h"

namespace RE
{
	class hknpQueryFilterData
	{
	public:
		// members
		hknpMaterialId          materialId;           // 00
		hkPadSpu<std::uint32_t> collisionFilterInfo;  // 04
		hkPadSpu<std::uint64_t> userData;             // 08
	};
	static_assert(sizeof(hknpQueryFilterData) == 0x10);
}
