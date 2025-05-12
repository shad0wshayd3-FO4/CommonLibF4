#pragma once

namespace RE
{
	struct BGSActorEvent
	{
	public:
		// member
		ActorHandle actor;  // 00
	};
	static_assert(sizeof(BGSActorEvent) == 0x4);
}
