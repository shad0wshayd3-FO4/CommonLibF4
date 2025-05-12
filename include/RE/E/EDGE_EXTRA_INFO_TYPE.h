#pragma once

namespace RE
{
	enum class EDGE_EXTRA_INFO_TYPE : std::int32_t
	{
		kInvalid = -1,
		kPortal = 0x0,
		kLedgeUp = 0x1,
		kLedgeDown = 0x2,
		kEnableDisablePortal = 0x3
	};
}
