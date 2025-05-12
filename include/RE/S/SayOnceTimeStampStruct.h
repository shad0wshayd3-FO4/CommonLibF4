#pragma once

namespace RE
{
	struct SayOnceTimeStampStruct
	{
	public:
		// members
		std::uint32_t date;  // 0
		float         hour;  // 4
	};
	static_assert(sizeof(SayOnceTimeStampStruct) == 0x8);
}
