#pragma once

namespace RE
{
	class BGSActorEvent
	{
	public:
		// member
		ActorHandle actor;  // 00
	};
	static_assert(sizeof(BGSActorEvent) == 0x4);
}
