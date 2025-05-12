#pragma once

namespace RE
{
	template <class T>
	class __declspec(novtable) BSTCommonScrapHeapMessageQueue :
		public BSTCommonMessageQueue<T>
	{
	public:
		// override
		virtual bool DoTryPush([[maybe_unused]] const T& a_message) override;  // 05
		virtual bool DoTryPop([[maybe_unused]] T& a_message) override;         // 06

		// members
		ScrapHeap*                scrapHeap;  // 10
		BSScrapHeapQueueElem<T>*  head;       // 18
		BSScrapHeapQueueElem<T>** tail;       // 20
	};
}
