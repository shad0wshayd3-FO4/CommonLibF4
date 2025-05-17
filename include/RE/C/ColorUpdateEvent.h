#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class ColorUpdateEvent
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<ColorUpdateEvent>;

	public:
		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			static REL::Relocation<EventSource_t**> singleton{ ID::ColorUpdateEvent::GetEventSource };
			if (!*singleton) {
				*singleton = new EventSource_t(&BSTGlobalEvent::GetSingleton()->eventSourceSDMKiller);
			}
			return *singleton;
		}
	};
	static_assert(std::is_empty_v<ColorUpdateEvent>);
}
