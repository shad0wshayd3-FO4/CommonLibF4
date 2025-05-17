#pragma once

namespace RE
{
	namespace LevelIncrease
	{
		class Event
		{
		public:
			// members
			std::uint32_t newLevel;  // 00
		};
		static_assert(sizeof(Event) == 0x4);

		[[nodiscard]] static BSTEventSource<LevelIncrease::Event>* GetEventSource()
		{
			using func_t = decltype(&LevelIncrease::GetEventSource);
			static REL::Relocation<func_t> func{ ID::LevelIncrease::GetEventSource };
			return func();
		}
	}
}
