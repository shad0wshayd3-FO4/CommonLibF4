#pragma once

namespace RE
{
	class BSNavmeshCoverEdge :
		public BSNavmeshCoverEdgeBase  // 0
	{
	public:
		// members
		std::uint16_t vertexArray[2];  // 0
		std::uint32_t data;            // 4
	};
	static_assert(sizeof(BSNavmeshCoverEdge) == 0x8);
}
