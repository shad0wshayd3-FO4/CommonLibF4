#pragma once

namespace RE
{
	class CONT_DATA
	{
	public:
		// members
		std::int8_t contFlags;  // 00
	};
	static_assert(sizeof(CONT_DATA) == 0x1);
}
