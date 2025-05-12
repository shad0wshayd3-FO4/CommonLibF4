#pragma once

namespace RE
{
	class CanDisplayNextHUDMessage :
		public BSTValueEvent<bool>
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<CanDisplayNextHUDMessage>;

	public:
		CanDisplayNextHUDMessage(bool a_value)
		{
			optionalValue = a_value;
		}

		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			static REL::Relocation<EventSource_t**> singleton{ REL::ID(344866) };
			if (!*singleton) {
				*singleton = new EventSource_t(&BSTGlobalEvent::GetSingleton()->eventSourceSDMKiller);
			}
			return *singleton;
		}
	};
	static_assert(sizeof(CanDisplayNextHUDMessage) == 0x2);
}
