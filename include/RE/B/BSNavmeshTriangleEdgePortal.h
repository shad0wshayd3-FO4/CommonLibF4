#pragma once

namespace RE
{
	struct BSNavmeshTriangleEdgePortal
	{
	public:
		// members
		std::uint32_t otherMeshID;  // 0
		std::uint16_t triangle;     // 4
		std::int8_t   edgeIndex;    // 6
	};
	static_assert(sizeof(BSNavmeshTriangleEdgePortal) == 0x8);
}
