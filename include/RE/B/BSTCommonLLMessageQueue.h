#pragma once

namespace RE
{
	template <class T>
	class __declspec(novtable) BSTCommonLLMessageQueue :
		public BSTCommonMessageQueue<T>  // 00
	{
	public:
		// members
		BSTFreeList<T>*      freeList;  // 10
		BSTFreeListElem<T>*  head;      // 18
		BSTFreeListElem<T>** tail;      // 20
	};
}
