#pragma once

namespace RE
{
	struct PowerArmorLightData
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<PowerArmorLightData>;

	public:
		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			static REL::Relocation<EventSource_t**> singleton{ REL::ID(120809) };
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
