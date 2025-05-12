#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	struct DoBeforeNewOrLoadCompletedEvent
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<DoBeforeNewOrLoadCompletedEvent>;

	public:
		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			static REL::Relocation<EventSource_t**> singleton{ REL::ID(787908) };
			if (!*singleton) {
				*singleton = new EventSource_t(&BSTGlobalEvent::GetSingleton()->eventSourceSDMKiller);
			}
			return *singleton;
		}
	};
	static_assert(sizeof(DoBeforeNewOrLoadCompletedEvent) == 0x1);
}
