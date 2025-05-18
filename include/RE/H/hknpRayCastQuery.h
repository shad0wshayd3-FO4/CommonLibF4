#pragma once

#include "RE/H/hkFlags.h"
#include "RE/H/hkcdRay.h"
#include "RE/H/hkcdRayQueryFlags.h"
#include "RE/H/hknpCollisionQuery.h"

namespace RE
{
	class hknpRayCastQuery :
		public hknpCollisionQuery
	{
	public:
		// members
		hkcdRay                                         ray;          // 20
		hkFlags<hkcdRayQueryFlags::Enum, std::uint32_t> flags;        // 50
		std::byte                                       pad54[0x0C];  // 54
	};
	static_assert(sizeof(hknpRayCastQuery) == 0x60);
}
