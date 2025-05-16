#pragma once

namespace Scaleform
{
	class StringDataPtr
	{
	public:
		// members
		const char*   str;   // 00
		std::uint64_t size;  // 08
	};
	static_assert(sizeof(StringDataPtr) == 0x10);
}
