#pragma once

namespace RE
{
	struct BSNavmeshEdgeExtraInfo
	{
	public:
		// members
		REX::EnumSet<EDGE_EXTRA_INFO_TYPE, std::int32_t> type;    // 0
		BSNavmeshTriangleEdgePortal                      portal;  // 4
	};
	static_assert(sizeof(BSNavmeshEdgeExtraInfo) == 0xC);
}
