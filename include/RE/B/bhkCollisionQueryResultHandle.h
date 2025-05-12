#pragma once

namespace RE
{
	struct bhkCollisionQueryResultHandle
	{
	public:
		// members
		std::uint64_t data;  // 0
	};
	static_assert(sizeof(bhkCollisionQueryResultHandle) == 0x8);
}
