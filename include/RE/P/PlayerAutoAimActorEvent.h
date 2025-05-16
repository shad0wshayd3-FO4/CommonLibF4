#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/B/BSPointerHandle.h"

namespace RE
{
	class PlayerAutoAimActorEvent :
		public BSTValueEvent<ActorHandle>  // 0
	{
	public:
	};
	static_assert(sizeof(PlayerAutoAimActorEvent) == 0x8);
}
