#pragma once

namespace RE
{
	struct VOICE_TYPE_DATA
	{
	public:
		// members
		std::int8_t flags;
	};
	static_assert(sizeof(VOICE_TYPE_DATA) == 0x1);
}
