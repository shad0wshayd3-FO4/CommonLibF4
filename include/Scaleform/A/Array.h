#pragma once

#include "Scaleform/A/Allocator.h"
#include "Scaleform/S/StatBasicValues.h"

namespace Scaleform
{
	class MemoryHeap;

	struct ArrayDefaultPolicy
	{
	public:
		~ArrayDefaultPolicy() noexcept {}

		// members
		std::size_t capacity;  // 0
	};
	static_assert(sizeof(ArrayDefaultPolicy) == 0x8);

	template <std::int32_t MinCapacity = 0, std::int32_t Granularity = 4, bool NeverShrink = false>
	struct ArrayConstPolicy
	{
	public:
		~ArrayConstPolicy() noexcept {}

		// members
		std::size_t capacity;  // 0
	};
	static_assert(sizeof(ArrayConstPolicy<>) == 0x8);

	template <class T, class Allocator, class SizePolicy>
	struct ArrayDataBase
	{
	public:
		// members
		T*          data;    // 00
		std::size_t size;    // 08
		SizePolicy  policy;  // 10
	};
	static_assert(sizeof(ArrayDataBase<void*, void*, ArrayDefaultPolicy>) == 0x18);

	template <class T, class Allocator, class SizePolicy>
	struct ArrayData :
		public ArrayDataBase<T, Allocator, SizePolicy>
	{
	public:
	};
	static_assert(sizeof(ArrayData<void*, void*, ArrayDefaultPolicy>) == 0x18);

	template <class T, class Allocator, class SizePolicy>
	struct ArrayDataDH :
		ArrayDataBase<T, Allocator, SizePolicy>
	{
	public:
		// members
		const MemoryHeap* pHeap;
	};
	static_assert(sizeof(ArrayDataDH<void*, void*, ArrayDefaultPolicy>) == 0x20);

	template <class T, class Allocator, class SizePolicy>
	struct ArrayDataCC :
		public ArrayDataBase<T, Allocator, SizePolicy>
	{
	public:
		T defaultValue;
	};
	static_assert(sizeof(ArrayDataCC<void*, void*, ArrayDefaultPolicy>) == 0x20);

	template <class T>
	class ArrayBase
	{
	public:
		// members
		T data;  // 00
	};
	static_assert(sizeof(ArrayBase<void*>) == 0x08);

	template <class T, std::int32_t SID = kStat_Default_Mem, class SizePolicy = ArrayDefaultPolicy>
	class Array :
		public ArrayBase<ArrayData<T, AllocatorGH<T, SID>, SizePolicy>>
	{
	public:
	};
	static_assert(sizeof(Array<void*, kStat_Default_Mem, ArrayDefaultPolicy>) == 0x18);

	template <class T, std::int32_t SID = kStat_Default_Mem, class SizePolicy = ArrayDefaultPolicy>
	class ArrayLH :
		public ArrayBase<ArrayData<T, AllocatorLH<T, SID>, SizePolicy>>
	{
	public:
	};
	static_assert(sizeof(ArrayLH<void*, kStat_Default_Mem, ArrayDefaultPolicy>) == 0x18);

	template <class T, std::int32_t SID = kStat_Default_Mem, class SizePolicy = ArrayDefaultPolicy>
	class ArrayDH :
		public ArrayBase<ArrayDataDH<T, AllocatorDH<T, SID>, SizePolicy>>
	{
	public:
	};
	static_assert(sizeof(ArrayDH<void*, kStat_Default_Mem, ArrayDefaultPolicy>) == 0x20);

	template <class T, std::int32_t SID = kStat_Default_Mem, class SizePolicy = ArrayDefaultPolicy>
	class ArrayCC :
		public ArrayBase<ArrayDataCC<T, AllocatorLH<T, SID>, SizePolicy>>
	{
	public:
	};
	static_assert(sizeof(ArrayCC<void*, kStat_Default_Mem, ArrayDefaultPolicy>) == 0x20);

	template <class T, std::int32_t SID = kStat_Default_Mem, class SizePolicy = ArrayDefaultPolicy>
	class ArrayPOD :
		public ArrayBase<ArrayData<T, AllocatorGH_POD<T, SID>, SizePolicy>>
	{
	public:
	};
	static_assert(sizeof(ArrayPOD<void*, kStat_Default_Mem, ArrayDefaultPolicy>) == 0x18);
}
