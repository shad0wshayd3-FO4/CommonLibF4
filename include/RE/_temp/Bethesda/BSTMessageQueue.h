#pragma once

#include "RE/Bethesda/BSTFreeList.h"

namespace RE
{
	template <class T>
	class BSScrapHeapQueueElem;

	template <class T>
	class __declspec(novtable) BSTMessageQueue
	{
	public:
		virtual ~BSTMessageQueue() = default;  // 00

		// add
		virtual bool Push(const T& a_message) = 0;     // 01
		virtual bool TryPush(const T& a_message) = 0;  // 02
		virtual bool Pop(T& a_message) = 0;            // 03
		virtual bool TryPop(T& a_message) = 0;         // 04
	};

	template <class T>
	class __declspec(novtable) BSTCommonMessageQueue :
		public BSTMessageQueue<T>  // 00
	{
	public:
		// override (BSTMessageQueue<T>)
		bool Push(const T& a_message) override;     // 01
		bool TryPush(const T& a_message) override;  // 02
		bool Pop(T& a_message) override;            // 03
		bool TryPop(T& a_message) override;         // 04

		// add
		virtual bool DoTryPush([[maybe_unused]] const T& a_message) { return false; }  // 05
		virtual bool DoTryPop([[maybe_unused]] T& a_message) { return false; }         // 06

		// members
		std::uint32_t lock;  // 08
	};

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

	struct BSTLocklessQueue
	{
	public:
		template <class T, std::uint32_t SIZE, std::uint32_t UNKNOWN>
		class alignas(0x80) PtrMultiProdCons
		{
		public:
			// members
			T* data[SIZE];                                   // 00
			alignas(0x80) volatile std::uint32_t start;      // ??
			alignas(0x80) volatile std::uint32_t fetched;    // ??
			alignas(0x80) volatile std::uint32_t end;        // ??
			alignas(0x80) volatile std::uint32_t allocated;  // ??
		};
		static_assert(sizeof(PtrMultiProdCons<void*, 128, 0>) == 0x600);

		template <class QueueContainer, class T, std::uint32_t SIZE, std::uint32_t UNKNOWN>
		struct alignas(0x80) ObjQueueBase
		{
		public:
			// members
			T              data[SIZE];  // 00
			QueueContainer queued;      // ??
			QueueContainer free;        // ??
		};
		static_assert(sizeof(ObjQueueBase<PtrMultiProdCons<void*, 128, 0>, void*, 64, 0>) == 0xE00);

		template <class T, std::uint32_t SIZE, std::uint32_t UNKNOWN>
		class alignas(0x80) ObjMultiProdCons :
			public ObjQueueBase<PtrMultiProdCons<T, SIZE * 2, UNKNOWN>, T, SIZE, UNKNOWN>
		{};
		static_assert(sizeof(ObjMultiProdCons<void*, 64, 0>) == 0xE00);
	};

	// TODO: This isn't accurate, this is contains a statically allocated BSTLocklessQueue, figure out how to do this
	template <class T, std::size_t SIZE>
	class __declspec(novtable) alignas(0x80) BSTCommonStaticMessageQueue :
		public BSTMessageQueue<T>  // 00
	{
	public:
		virtual ~BSTCommonStaticMessageQueue();  // 00

		// override (BSTMessageQueue<T>)
		bool Push(const T& a_message) override;     // 01
		bool TryPush(const T& a_message) override;  // 02
		bool Pop(T& a_message) override;            // 03
		bool TryPop(T& a_message) override;         // 04

		// members
		alignas(0x80) char queueBuffer[sizeof(T) * SIZE];              // 10
		BSTLocklessQueue::ObjMultiProdCons<T, 128, 0>* locklessQueue;  // ??
	};
}
