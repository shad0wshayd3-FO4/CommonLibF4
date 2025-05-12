#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTSingleton.h"
#include "RE/Bethesda/BSTSmartPointer.h"
#include "RE/Bethesda/UserEvents.h"

namespace RE
{
	class InputEnableLayerDestroyedEvent;
	class OtherEventEnabledEvent;
	class UserEventEnabledEvent;

	namespace OtherInputEvents
	{
		enum class OTHER_EVENT_FLAG
		{
			kAll = static_cast<std::underlying_type_t<OTHER_EVENT_FLAG>>(-1),

			kJournalTabs = 1 << 0,
			kActivation = 1 << 1,
			kFastTravel = 1 << 2,
			kPOVChange = 1 << 3,
			kVATS = 1 << 4,
			kFavorites = 1 << 5,
			kPipboyLight = 1 << 6,
			kZKey = 1 << 7,
			kRunning = 1 << 8,
			kCursor = 1 << 9,
			kSprinting = 1 << 10,
		};
	}

	using OEFlag = OtherInputEvents::OTHER_EVENT_FLAG;
}
