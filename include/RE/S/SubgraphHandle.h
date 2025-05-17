#pragma once

namespace RE
{
	class SubgraphHandle
	{
	public:
		// members
		std::uint64_t handle;  // 0
	};
	static_assert(sizeof(SubgraphHandle) == 0x8);
}
