#pragma once

namespace RE
{
	enum class UI_MESSAGE_TYPE
	{
		kUpdate = 0x0,
		kShow = 0x1,
		kReshow = 0x2,
		kHide = 0x3,
		kForceHide = 0x4,
		kScaleformEvent = 0x5,
		kUserEvent = 0x6,
		kInventoryUpdate = 0x7,
		kUserProfileChange = 0x8,
		kMUStatusChange = 0x9,
		kResumeCaching = 0xA,
		kUpdateController = 0xB,
		kChatterEvent = 0xC,
		kTotal = 0xD
	};
}
