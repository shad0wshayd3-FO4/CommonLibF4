#pragma once

#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	namespace PlayerActiveEffectChanged
	{
		enum Status : std::int32_t
		{
			kAdded = 0x0,
			kRemoved = 0x1,
			kStatusChanged = 0x2
		};

		class Event
		{
		public:
			// members
			BSTSmartPointer<ActiveEffect, BSTSmartPointerIntrusiveRefCount> effect;  // 00
			PlayerActiveEffectChanged::Status                               status;  // 08
		};
	}
}
