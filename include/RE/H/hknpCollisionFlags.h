#pragma once

namespace RE
{
	struct hknpCollisionFlags :
		public hkFlags<hknpCollisionFlagsEnum, std::int32_t>
	{
		using enum hknpCollisionFlagsEnum;
	};
	static_assert(sizeof(hknpCollisionFlags) == 0x4);
}
