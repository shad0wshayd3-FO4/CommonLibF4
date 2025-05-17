#pragma once

#include "RE/B/BGSActorEvent.h"

namespace RE
{
	class BGSActorDeathEvent :
		public BGSActorEvent
	{
	public:
		// members
		ActorHandle attacker;  // 04
		float       damage;    // 08
	};
	static_assert(sizeof(BGSActorDeathEvent) == 0xC);
}
