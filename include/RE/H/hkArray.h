#pragma once

#include "RE/H/hkContainerHeapAllocator.h"

namespace RE
{
	template <class T>
	class hkArrayBase
	{
	public:
		// members
		T*           data;              // 00
		std::int32_t size;              // 08
		std::int32_t capacityAndFlags;  // 0C
	};
	static_assert(sizeof(hkArrayBase<void>) == 0x10);

	template <class T, class Allocator = hkContainerHeapAllocator>
	class hkArray :
		public hkArrayBase<T>
	{
	public:
	};
	static_assert(sizeof(hkArray<void>) == 0x10);

	template <class T, std::size_t N, class Allocator = hkContainerHeapAllocator>
	class hkInplaceArray :
		public hkArray<T, Allocator>
	{
	public:
		// members
		T storage[N];  // 10
	};
	static_assert(sizeof(hkInplaceArray<std::byte, 32>) == 0x30);

	template <class T, std::size_t N, class Allocator = hkContainerHeapAllocator>
	class hkInplaceArrayAligned16 :
		public hkArray<T, Allocator>
	{
	public:
		// members
		std::byte    padding[0x10];           // 10
		std::uint8_t storage[sizeof(T) * N];  // 20
	};
	static_assert(sizeof(hkInplaceArrayAligned16<void*, 24>) == 0xE0);

	template <class T>
	class hkLocalArray :
		public hkArray<T>
	{
	public:
		// members
		T*           localMemory;      // 10
		std::int32_t initialCapacity;  // 18
	};
	static_assert(sizeof(hkLocalArray<void>) == 0x20);
}
