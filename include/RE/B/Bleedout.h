#pragma once

namespace RE
{
	namespace Bleedout
	{
		struct Event
		{
			// members
			Actor* actorBleedingOut;  // 00
		};
		static_assert(sizeof(Event) == 0x8);
	}
}
