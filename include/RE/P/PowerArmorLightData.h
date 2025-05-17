#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class PowerArmorLightData
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<PowerArmorLightData>;

	public:
		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			static REL::Relocation<EventSource_t**> singleton{ ID::PowerArmorLightData::GetEventSource };
			if (!*singleton) {
				*singleton = new EventSource_t(&BSTGlobalEvent::GetSingleton()->eventSourceSDMKiller);
			}
			return *singleton;
		}

		// members
		bool lightOn;  // 00
	};
	static_assert(sizeof(PowerArmorLightData) == 0x1);
}
