#pragma once

namespace RE
{
	struct TESLocationClearedEvent
	{
		// members
		const BGSLocation* location;  // 00
	};
	static_assert(sizeof(TESLocationClearedEvent) == 0x08);
}
