#pragma once

namespace RE
{
	class TESFileArray;

	struct TESFileContainer
	{
	public:
		// members
		const TESFileArray* array;  // 0
	};
	static_assert(sizeof(TESFileContainer) == 0x8);
}
