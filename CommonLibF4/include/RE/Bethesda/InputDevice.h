#pragma once

namespace RE
{
	enum class INPUT_DEVICE : std::int32_t
	{
		kNone = static_cast<std::underlying_type_t<INPUT_DEVICE>>(-1),

		kKeyboard = 0,
		kMouse,
		kGamepad,

		kSupported,

		kKinect = 3,
		kVirtualKeyboard,

		kTotal
	};

	enum class INPUT_DEVICE_LIGHT_STATE : std::int32_t
	{
		kDeviceLightStatePowerArmorLight = 0x0,
		kDeviceLightStatePowerArmor = 0x1,
		kDeviceLightStatePipboyLight = 0x2,
	};
}
