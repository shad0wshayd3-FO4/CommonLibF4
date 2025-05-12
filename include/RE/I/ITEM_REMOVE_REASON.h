#pragma once

namespace RE
{
	enum class ITEM_REMOVE_REASON
	{
		kNone = 0x0,
		kStealing = 0x1,
		kSelling = 0x2,
		KDropping = 0x3,
		kStoreContainer = 0x4,
		kStoreTeammate = 0x5
	};
}
