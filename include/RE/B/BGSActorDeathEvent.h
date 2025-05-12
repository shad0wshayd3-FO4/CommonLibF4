#pragma once

namespace RE
{
	struct BGSActorDeathEvent : public BGSActorEvent
	{
	public:
		// members
		ActorHandle attacker;  // 04
		float       damage;    // 08
	};
	static_assert(sizeof(BGSActorDeathEvent) == 0xC);
}
