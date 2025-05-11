#pragma once

#include "RE/Havok/hkRelArray.h"
#include "RE/Havok/hknpShape.h"

namespace RE
{
	class hkcdVertex;

	class __declspec(novtable) hknpConvexShape :
		public hknpShape
	{
	public:
		inline static constexpr auto RTTI{ RTTI::hknpConvexShape };
		inline static constexpr auto VTABLE{ VTABLE::hknpConvexShape };

		// members
		hkRelArray<hkcdVertex> vertices;  // 30
	};
	static_assert(sizeof(hknpConvexShape) == 0x40);
}
