#pragma once

namespace RE
{
	template <class T>
	class AnimationStanceNodeLocationData
	{
	public:
		// members
		T nodeLocationArray[3];  // 00
	};
	static_assert(sizeof(AnimationStanceNodeLocationData<void*>) == 0x18);
}
