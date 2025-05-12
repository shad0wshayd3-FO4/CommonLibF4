#pragma once

namespace RE
{
	class CFilter
	{
	public:
		~CFilter() noexcept {}  // intentional

		// members
		std::uint32_t filter;  // 0
	};
	static_assert(sizeof(CFilter) == 0x4);
}
