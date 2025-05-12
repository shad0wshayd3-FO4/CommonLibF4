#pragma once

namespace RE
{
	struct hknpCollisionDispatchType
	{
		enum Enum
		{
			kNone,
			kConvex,
			kComposite,
			kDistanceField,
			kUser
		};
	};
	static_assert(std::is_empty_v<hknpCollisionDispatchType>);
}
