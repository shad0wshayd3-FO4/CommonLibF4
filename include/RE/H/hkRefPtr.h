#pragma once

namespace RE
{
	template <class T>
	class hkRefPtr
	{
	public:
		// members
		T* ptr;  // 00
	};
	static_assert(sizeof(hkRefPtr<void>) == 0x08);
}
