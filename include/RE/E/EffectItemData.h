#pragma once

namespace RE
{
	struct EffectItemData
	{
	public:
		// members
		float        magnitude;  // 0
		std::int32_t area;       // 4
		std::int32_t duration;   // 8
	};
	static_assert(sizeof(EffectItemData) == 0xC);
}
