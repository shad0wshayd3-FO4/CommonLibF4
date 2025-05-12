#pragma once

namespace RE
{
	struct TESFileContainer
	{
	public:
		// members
		const TESFileArray* array;  // 0
	};
	static_assert(sizeof(TESFileContainer) == 0x8);
}
