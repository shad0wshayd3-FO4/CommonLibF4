#pragma once

namespace RE
{
	namespace FatmanDeaths
	{
		struct Event
		{
			Actor* victim;
		};
		static_assert(sizeof(Event) == 0x8);
	}
}
