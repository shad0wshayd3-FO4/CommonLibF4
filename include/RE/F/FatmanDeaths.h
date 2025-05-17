#pragma once

namespace RE
{
	namespace FatmanDeaths
	{
		class Event
		{
		public:
			// members
			Actor* victim;  // 00
		};
		static_assert(sizeof(Event) == 0x8);
	}
}
