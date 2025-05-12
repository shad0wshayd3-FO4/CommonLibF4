#pragma once

namespace RE
{
	enum class INPUT_EVENT_TYPE : std::int32_t
	{
		kButton = 0x0,
		kMouseMove = 0x1,
		kCursorMove = 0x2,
		kChar = 0x3,
		kThumbstick = 0x4,
		kDeviceConnect = 0x5,
		kKinect = 0x6,
		kNone = 0x7
	};
}
