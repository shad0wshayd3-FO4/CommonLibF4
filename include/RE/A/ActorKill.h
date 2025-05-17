#pragma once

namespace RE
{
	namespace ActorKill
	{
		class Event
		{
		public:
			// members
			const Actor* killer;
			const Actor* victim;
		};
		static_assert(sizeof(Event) == 0x10);
	}
}
