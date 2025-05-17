#pragma once

namespace RE
{
	class UnloadedRefData
	{
	public:
		// members
		std::uint32_t refID;          // 0
		std::uint32_t parentSpaceID;  // 4
		std::uint32_t cellKey;        // 8
	};
	static_assert(sizeof(UnloadedRefData) == 0xC);
}
