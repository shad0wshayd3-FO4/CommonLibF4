#pragma once

namespace RE
{
	struct PATH_DATA
	{
	public:
		// members
		std::int8_t flags;  // 0
	};
	static_assert(sizeof(PATH_DATA) == 0x1);
}
