#pragma once

namespace RE
{
	class CachedValueData
	{
	public:
		// members
		float value;  // 0
		bool  dirty;  // 4
	};
	static_assert(sizeof(CachedValueData) == 0x8);
}
