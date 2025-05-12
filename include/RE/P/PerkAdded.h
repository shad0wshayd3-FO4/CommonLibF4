#pragma once

namespace RE
{
	namespace PerkAdded
	{
		struct Event
		{
			const Actor*   adder;
			const BGSPerk* perk;
			std::uint8_t   rank;
		};
		static_assert(sizeof(Event) == 0x18);
	}
}
