#pragma once

namespace RE
{
	class hknpCollisionQueryType
	{
	public:
		enum class Enum
		{
			kUndefined = 0x0,
			kRayCast = 0x1,
			kShapeCast = 0x2,
			kPointQuery = 0x3,
			kGetClosestPoints = 0x4,
			kQueryAABB = 0x5
		};
	};
	static_assert(std::is_empty_v<hknpCollisionQueryType>);
}
