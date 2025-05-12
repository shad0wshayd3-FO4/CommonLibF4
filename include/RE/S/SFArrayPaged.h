#pragma once

#include "RE/Scaleform/Kernel/SF_Allocator.h"

namespace RE::Scaleform
{
	template <class T>
	class ConstructorPagedPOD : public ConstructorPOD<T>
	{
	public:
	};

	template <class T>
	class ConstructorPagedMov : public ConstructorMov<T>
	{
	public:
	};

	template <typename T>
	class ConstructorPagedMovCC : public ConstructorMov<T>
	{
	public:
	};

	template <class T, int SID>
	struct AllocatorPagedGH_POD : AllocatorBaseGH<SID>, ConstructorPagedPOD<T>
	{};
	template <class T, int SID>
	struct AllocatorPagedGH : AllocatorBaseGH<SID>, ConstructorPagedMov<T>
	{};

	template <class T, int SID>
	struct AllocatorPagedLH_POD : AllocatorBaseLH<SID>, ConstructorPagedPOD<T>
	{};
	template <class T, int SID>
	struct AllocatorPagedLH : AllocatorBaseLH<SID>, ConstructorPagedMov<T>
	{};

	template <typename T, int SID>
	struct AllocatorPagedCC : AllocatorBaseLH<SID>, ConstructorPagedMovCC<T>
	{};

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
	class ArrayPaged :
		public ArrayPagedBase<T, PageSh, PtrPoolInc, AllocatorPagedGH<T, SID>>
	{
	public:
	};

	template <class T, std::int32_t PageSh = 6, std::int32_t PtrPoolInc = 64, std::int32_t SID = kStat_Default_Mem>
	class ArrayPagedPOD :
		public ArrayPagedBase<T, PageSh, PtrPoolInc, AllocatorPagedGH_POD<T, SID>>
	{
	public:
	};

	template <class T, std::int32_t PageSh = 0, std::int32_t PtrPoolInc = 0, std::int32_t SID = 0>
	class ArrayPagedCC :
		public ArrayPagedBase<T, PageSh, PtrPoolInc, AllocatorPagedCC<T, SID>>
	{
	public:
		T defaultValue;  // 28
	};
	static_assert(sizeof(ArrayPagedCC<void*>) == 0x30);
}
