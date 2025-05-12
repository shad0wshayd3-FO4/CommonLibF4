#pragma once

namespace RE
{
	class PlayerAutoAimActorEvent :
		public BSTValueEvent<ActorHandle>  // 0
	{
	public:
	};
	static_assert(sizeof(PlayerAutoAimActorEvent) == 0x8);
}
