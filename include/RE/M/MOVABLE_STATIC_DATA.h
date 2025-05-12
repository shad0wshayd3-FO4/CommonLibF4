#pragma once

namespace RE
{
	struct MOVABLE_STATIC_DATA
	{
	public:
		// members
		std::int8_t flags;  // 0
	};
	static_assert(sizeof(MOVABLE_STATIC_DATA) == 0x1);
}
