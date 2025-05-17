#pragma once

namespace RE
{
	class TESFileArray;

	class TESFileContainer
	{
	public:
		// members
		const TESFileArray* array;  // 0
	};
	static_assert(sizeof(TESFileContainer) == 0x8);
}
