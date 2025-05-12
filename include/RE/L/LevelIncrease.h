#pragma once

namespace RE
{
	namespace LevelIncrease
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<Event>* GetEventSource()
			{
				using func_t = decltype(&Event::GetEventSource);
				static REL::Relocation<func_t> func{ REL::ID(2233736) };
				return func();
			}

			std::uint32_t newLevel;  // 00
		};
		static_assert(sizeof(Event) == 0x4);
	}
}
