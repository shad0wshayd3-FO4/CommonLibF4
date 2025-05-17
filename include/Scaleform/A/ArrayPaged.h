#pragma once

#include "Scaleform/A/Allocator.h"
#include "Scaleform/S/StatBasicValues.h"

namespace Scaleform
{
	template <class T, std::int32_t PageSh = 0, std::int32_t PtrPoolInc = 0, class Allocator = AllocatorPagedCC<T, 0>>
	class ArrayPagedBase :
		public Allocator
	{
	public:
		// members
		std::uint64_t size;      // 08
		std::uint64_t numPages;  // 10
		std::uint64_t maxPages;  // 18
		T**           pages;     // 20
	};
	static_assert(sizeof(ArrayPagedBase<void*>) == 0x28);

	template <class T, std::int32_t PageSh = 6, std::int32_t PtrPoolInc = 64, std::int32_t SID = kStat_Default_Mem>
	class ArrayPagedPOD :
		public ArrayPagedBase<T, PageSh, PtrPoolInc, AllocatorPagedGH_POD<T, SID>>
	{
	public:
	};
	static_assert(sizeof(ArrayPagedPOD<void*>) == 0x28);

	template <class T, std::int32_t PageSh = 0, std::int32_t PtrPoolInc = 0, std::int32_t SID = 0>
	class ArrayPagedCC :
		public ArrayPagedBase<T, PageSh, PtrPoolInc, AllocatorPagedCC<T, SID>>
	{
	public:
		T defaultValue;  // 28
	};
	static_assert(sizeof(ArrayPagedCC<void*>) == 0x30);
}
