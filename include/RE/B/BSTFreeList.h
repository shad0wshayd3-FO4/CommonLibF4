#pragma once

namespace RE
{
    template <class T>
	class __declspec(novtable) BSTFreeList
	{
	public:
		virtual ~BSTFreeList();  // 00

		// members
		std::uint32_t       lock;  // 08
		BSTFreeListElem<T>* free;  // 10
	};
	//static_assert(sizeof(BSTFreeList<void*>) == 0x18);
}
