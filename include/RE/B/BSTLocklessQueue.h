#pragma once

namespace RE
{
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
		{
		};
		static_assert(sizeof(ObjMultiProdCons<void*, 64, 0>) == 0xE00);
	};
}
