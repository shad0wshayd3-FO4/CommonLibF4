#pragma once

namespace RE
{
	class CurrentRadiationSourceCount :
		public BSTValueEvent<std::uint32_t>
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<CurrentRadiationSourceCount>;

	public:
		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			static REL::Relocation<EventSource_t**> singleton{ REL::ID(2696196) };
			if (!*singleton) {
				*singleton = new EventSource_t(&BSTGlobalEvent::GetSingleton()->eventSourceSDMKiller);
			}
			return *singleton;
		}
	};
	static_assert(sizeof(CurrentRadiationSourceCount) == 0x8);
}
