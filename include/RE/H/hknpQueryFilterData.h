#pragma once

#include "RE/H/hknpMaterialId.h"
#include "RE/H/hkPadSpu.h"

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
