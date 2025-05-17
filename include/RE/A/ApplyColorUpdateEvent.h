#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class ApplyColorUpdateEvent
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<ApplyColorUpdateEvent>;

	public:
		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			static REL::Relocation<EventSource_t**> singleton{ REL::ID(2707340) };
			if (!*singleton) {
				*singleton = new EventSource_t(&BSTGlobalEvent::GetSingleton()->eventSourceSDMKiller);
			}
			return *singleton;
		}
	};
	static_assert(std::is_empty_v<ApplyColorUpdateEvent>);
}
