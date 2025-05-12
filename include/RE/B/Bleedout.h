#pragma once

namespace RE
{
	namespace Bleedout
	{
		struct Event
		{
			Actor* actorBleedingOut;
		};
		static_assert(sizeof(Event) == 0x8);
	}
}
