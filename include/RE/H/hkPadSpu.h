#pragma once

namespace RE
{
	template <class T>
	class hkPadSpu
	{
	public:
		// members
		T storage;  // 00
	};
	static_assert(sizeof(hkPadSpu<void*>) == 0x08);
}
