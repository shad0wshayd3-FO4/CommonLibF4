#pragma once

namespace RE
{
	class DIALOGUE_DATA
	{
	public:
		// members
		std::int8_t   flags;    // 0
		std::int8_t   type;     // 1
		std::uint16_t subtype;  // 2
	};
	static_assert(sizeof(DIALOGUE_DATA) == 0x4);
}
