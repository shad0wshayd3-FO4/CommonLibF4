#pragma once

namespace RE
{
	struct FILE_HEADER
	{
	public:
		// members
		float         version;     // 0
		std::uint32_t formCount;   // 4
		std::uint32_t nextFormID;  // 8
	};
	static_assert(sizeof(FILE_HEADER) == 0xC);
}
