#pragma once

namespace Scaleform::GFx::AS3
{
	template <typename T>
	class SPtr
	{
	public:
		// members
		T* object;  // 00
	};
	static_assert(sizeof(SPtr<void>) == 0x08);
}
