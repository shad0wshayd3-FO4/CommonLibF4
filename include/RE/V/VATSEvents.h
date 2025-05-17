#pragma once

#include "RE/V/VATS.h"

namespace RE
{
	namespace VATSEvents
	{
		class ModeChange
		{
		public:
			// members
			VATS::VATS_MODE_ENUM oldMode;  // 00
			VATS::VATS_MODE_ENUM newMode;  // 04
		};
		static_assert(sizeof(ModeChange) == 0x8);
	}
}
