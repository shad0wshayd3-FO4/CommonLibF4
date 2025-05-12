#pragma once

namespace RE
{
	template <class T>
	struct BSTFreeListElem
	{
	public:
		// members
		std::byte           rawElem[sizeof(T)];  // 00
		BSTFreeListElem<T>* next;                // ??
	};
}
