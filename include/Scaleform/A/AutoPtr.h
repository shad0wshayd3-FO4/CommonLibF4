#pragma once

namespace Scaleform
{
	template <class T>
	class AutoPtr
	{
	public:
		// members
		T*   object;  // 00
		bool owner;   // 08
	};
	static_assert(sizeof(AutoPtr<void>) == 0x10);
}
