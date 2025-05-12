#pragma once

namespace RE
{
	namespace FatmanDeaths
	{
		struct Event
		{
			// members
			Actor* victim;  // 00
		};
		static_assert(sizeof(Event) == 0x8);
	}
}
