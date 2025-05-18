#pragma once

#include "RE/H/hknpCollisionResult.h"

namespace RE
{
	class hknpRayCastQueryResult :
		public hknpCollisionResult
	{
	public:
	};
	static_assert(sizeof(hknpRayCastQueryResult) == 0x60);
}
