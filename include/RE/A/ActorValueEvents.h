#pragma once

namespace RE
{
	namespace ActorValueEvents
	{
		struct ActorValueChangedEvent
		{
		public:
			// members
			const ActorValueInfo& actorValue;  // 00
			TESObjectREFR*        owner;       // 08
		};
		static_assert(sizeof(ActorValueChangedEvent) == 0x10);
	}
}
