#pragma once

namespace RE
{
	namespace PerkAdded
	{
		class Event
		{
		public:
			const Actor*   adder;
			const BGSPerk* perk;
			std::uint8_t   rank;
		};
		static_assert(sizeof(Event) == 0x18);
	}
}
