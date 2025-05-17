#pragma once

namespace RE
{
	namespace PlayerLifeStateChanged
	{
		class Event
		{
		public:
			// members
			ACTOR_LIFE_STATE lifeState;  // 00
		};
		static_assert(sizeof(Event) == 0x4);
	}
}
