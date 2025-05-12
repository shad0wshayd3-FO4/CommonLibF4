#pragma once

namespace RE
{
	struct CLASS_DATA
	{
	public:
		// members
		std::int32_t serviceFlags;     // 0
		float        bleedoutDefault;  // 4
	};
	static_assert(sizeof(CLASS_DATA) == 0x8);
}
