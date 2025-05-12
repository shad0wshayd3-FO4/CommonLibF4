#pragma once

namespace RE
{
	class BSSaveDataSystemUtilityImage
	{
	public:
		// members
		std::uint32_t size;    // 00
		std::uint32_t width;   // 04
		std::uint32_t height;  // 08
		char*         buffer;  // 10
	};
	static_assert(sizeof(BSSaveDataSystemUtilityImage) == 0x18);
}
