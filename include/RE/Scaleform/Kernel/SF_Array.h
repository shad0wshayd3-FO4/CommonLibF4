#pragma once

#include "RE/Scaleform/Kernel/SF_Allocator.h"

namespace RE::Scaleform
{
	struct ArrayDefaultPolicy;

	struct ArrayDefaultPolicy
	{
	public:
		~ArrayDefaultPolicy() noexcept {}  // NOLINT(modernize-use-equals-default)

		// members
		std::size_t capacity;  // 0
	};
	static_assert(sizeof(ArrayDefaultPolicy) == 0x8);

	template <std::int32_t MinCapacity = 0, std::int32_t Granularity = 4, bool NeverShrink = false>
	struct ArrayConstPolicy
	{
	public:
		~ArrayConstPolicy() noexcept {}  // NOLINT(modernize-use-equals-default)

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

	template <class T, class Allocator, class SizePolicy>
	struct ArrayData :
		public ArrayDataBase<T, Allocator, SizePolicy>  // 0
	{
	public:
	};

	template <class T, class Allocator, class SizePolicy>
	struct ArrayDataDH :
		ArrayDataBase<T, Allocator, SizePolicy>
	{
	public:
		// members
		const MemoryHeap* pHeap;
	};

	template <class T, class Allocator, class SizePolicy>
	struct ArrayDataCC :
		public ArrayDataBase<T, Allocator, SizePolicy>
	{
	public:
		T defaultValue;
	};

	template <class ArrayData>
	class ArrayBase
	{
	public:
		// members
		ArrayData data;  // 0
	};

	template <class T, std::int32_t SID = kStat_Default_Mem, class SizePolicy = ArrayDefaultPolicy>
	class Array :
		public ArrayBase<ArrayData<T, AllocatorGH<T, SID>, SizePolicy>>  // 0
	{
	public:
	};

	template <class T, std::int32_t SID = kStat_Default_Mem, class SizePolicy = ArrayDefaultPolicy>
	class ArrayLH :
		public ArrayBase<ArrayData<T, AllocatorLH<T, SID>, SizePolicy>>
	{
	public:
	};

	template <class T, std::int32_t SID = kStat_Default_Mem, class SizePolicy = ArrayDefaultPolicy>
	class ArrayDH :
		public ArrayBase<ArrayDataDH<T, AllocatorDH<T, SID>, SizePolicy>>
	{
	public:
	};

	template <class T, std::int32_t SID = kStat_Default_Mem, class SizePolicy = ArrayDefaultPolicy>
	class ArrayCC :
		public ArrayBase<ArrayDataCC<T, AllocatorLH<T, SID>, SizePolicy>>
	{
	public:
	};
}
