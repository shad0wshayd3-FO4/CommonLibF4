#pragma once

namespace RE
{
	template <class T, std::uint32_t N>
	class __declspec(novtable) BSTStaticFreeList :
		public BSTFreeList<T>  // 00
	{
	public:
		// members
		BSTFreeListElem<T> elems[N];  // ??
	};
}
