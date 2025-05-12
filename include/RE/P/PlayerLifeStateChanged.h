#pragma once

namespace RE
{
	namespace PlayerLifeStateChanged
	{
		struct Event
		{
			ACTOR_LIFE_STATE lifeState;  // 00
		};
		static_assert(sizeof(Event) == 0x4);
	}
}
