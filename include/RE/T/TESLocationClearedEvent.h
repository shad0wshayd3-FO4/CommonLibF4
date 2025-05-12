#pragma once

namespace RE
{
	struct TESLocationClearedEvent
	{
		const BGSLocation* loc;  //00
	};
	static_assert(sizeof(TESLocationClearedEvent) == 0x8);
}
