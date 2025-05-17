#pragma once

namespace RE
{
	class SubgraphIdentifier
	{
	public:
		// members
		std::size_t identifier;  // 0
	};
	static_assert(sizeof(SubgraphIdentifier) == 0x8);
}
