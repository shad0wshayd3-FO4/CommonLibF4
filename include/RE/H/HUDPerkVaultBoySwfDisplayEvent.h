#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/H/HUDPerkVaultBoyData.h"

namespace RE
{
	class HUDPerkVaultBoySwfDisplayEvent :
		public BSTValueEvent<HUDPerkVaultBoyData>  // 00
	{
	public:
	};
	static_assert(sizeof(HUDPerkVaultBoySwfDisplayEvent) == 0x20);
}
