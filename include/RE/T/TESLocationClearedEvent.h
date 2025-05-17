#pragma once

namespace RE
{
	class TESLocationClearedEvent
	{
	public:
		// members
		const BGSLocation* location;  // 00
	};
	static_assert(sizeof(TESLocationClearedEvent) == 0x08);
}
