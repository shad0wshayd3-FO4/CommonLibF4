#pragma once

#include "RE/B/BSInputEventUser.h"

namespace RE
{
	struct __declspec(novtable) ScreenshotHandler :
		public BSInputEventUser  // 00
	{
		static constexpr auto RTTI{ RTTI::ScreenshotHandler };
		static constexpr auto VTABLE{ VTABLE::ScreenshotHandler };

		// members
		bool screenshotQueued;       // 10
		bool multiScreenshotQueued;  // 11
	};
	static_assert(sizeof(ScreenshotHandler) == 0x18);
}
