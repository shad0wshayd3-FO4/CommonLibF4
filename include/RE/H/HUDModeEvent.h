#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"

namespace RE
{
	class HUDModeType;

	class HUDModeEvent
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<HUDModeEvent>;

	public:
		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			static REL::Relocation<EventSource_t**> singleton{ REL::ID(683142) };
			if (!*singleton) {
				*singleton = new EventSource_t(&BSTGlobalEvent::GetSingleton()->eventSourceSDMKiller);
			}
			return *singleton;
		}

		// members
		const BSTArray<HUDModeType>* currentHUDModes;  // 00
	};
	static_assert(sizeof(HUDModeEvent) == 0x8);
}
