#pragma once

#include "RE/H/hknpQueryFilterData.h"

namespace RE
{
	class hknpCollisionFilter;

	class hknpCollisionQuery
	{
	public:
		// members
		hkPadSpu<hknpCollisionFilter*> filter;         // 00
		hknpQueryFilterData            filterData;     // 08
		std::uint8_t                   levelOfDetail;  // 18
	};
	static_assert(sizeof(hknpCollisionQuery) == 0x20);
}
