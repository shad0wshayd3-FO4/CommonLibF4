#pragma once

namespace RE
{
	enum class UI_MESSAGE_RESULTS : std::int32_t
	{
		kHandled = 0x0,
		kIgnore = 0x1,
		kPassOn = 0x2
	};
}
