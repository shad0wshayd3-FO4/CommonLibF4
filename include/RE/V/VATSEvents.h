#pragma once

namespace RE
{
	namespace VATSEvents
	{
		struct ModeChange
		{
			VATS::VATS_MODE_ENUM oldMode;  // 00
			VATS::VATS_MODE_ENUM newMode;  // 04
		};
		static_assert(sizeof(ModeChange) == 0x8);
	}
}
