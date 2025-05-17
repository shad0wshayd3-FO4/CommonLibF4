#pragma once

namespace RE
{
	namespace ActorItemEquipped
	{
		class Event
		{
		public:
			// members
			const TESBoundObject* item;      // 00
			const Actor*          equipper;  // 08
		};
		static_assert(sizeof(Event) == 0x10);
	}
}
