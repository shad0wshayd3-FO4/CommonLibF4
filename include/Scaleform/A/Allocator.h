#pragma once

#include "Scaleform/S/StatBasicValues.h"

namespace Scaleform
{
	template <std::int32_t SID = kStat_Default_Mem>
	class AllocatorBaseDH
	{
	public:
	};
	static_assert(std::is_empty_v<AllocatorBaseDH<kStat_Default_Mem>>);

	template <std::int32_t SID = kStat_Default_Mem>
	class AllocatorBaseGH
	{
	public:
	};
	static_assert(std::is_empty_v<AllocatorBaseGH<kStat_Default_Mem>>);

	template <std::int32_t SID = kStat_Default_Mem>
	class AllocatorBaseLH
	{
	public:
	};
	static_assert(std::is_empty_v<AllocatorBaseLH<kStat_Default_Mem>>);

	template <class T>
	class ConstructorPOD
	{
	public:
	};
	static_assert(std::is_empty_v<ConstructorPOD<void*>>);

	template <class T>
	class ConstructorMov
	{
	public:
	};
	static_assert(std::is_empty_v<ConstructorMov<void*>>);

	template <class T>
	class ConstructorCPP
	{
	public:
	};
	static_assert(std::is_empty_v<ConstructorCPP<void*>>);

	template <class T>
	class ConstructorPagedPOD :
		public ConstructorPOD<T>
	{
	public:
	};
	static_assert(std::is_empty_v<ConstructorPagedPOD<void*>>);

	template <class T>
	class ConstructorPagedMov :
		public ConstructorMov<T>
	{
	public:
	};
	static_assert(std::is_empty_v<ConstructorPagedMov<void*>>);

	template <typename T>
	class ConstructorPagedMovCC :
		public ConstructorMov<T>
	{
	public:
	};
	static_assert(std::is_empty_v<ConstructorPagedMovCC<void*>>);

	template <class T, std::int32_t SID = kStat_Default_Mem>
	class AllocatorGH :
		public AllocatorBaseGH<SID>,
		public ConstructorMov<T>
	{
	public:
	};
	static_assert(std::is_empty_v<AllocatorGH<void*, kStat_Default_Mem>>);

	template <class T, std::int32_t SID = kStat_Default_Mem>
	class AllocatorLH :
		public AllocatorBaseLH<SID>,
		public ConstructorMov<T>
	{
	public:
	};
	static_assert(std::is_empty_v<AllocatorLH<void*, kStat_Default_Mem>>);

	template <class T, std::int32_t SID = kStat_Default_Mem>
	class AllocatorDH :
		public AllocatorBaseDH<SID>,
		public ConstructorMov<T>
	{
	public:
	};
	static_assert(std::is_empty_v<AllocatorDH<void*, kStat_Default_Mem>>);

	template <class T, std::int32_t SID = kStat_Default_Mem>
	class AllocatorGH_POD :
		public AllocatorBaseGH<SID>,
		public ConstructorPOD<T>
	{
	public:
	};
	static_assert(std::is_empty_v<AllocatorGH_POD<void*, kStat_Default_Mem>>);

	template <class T, int SID>
	class AllocatorPagedGH :
		AllocatorBaseGH<SID>,
		ConstructorPagedMov<T>
	{
	public:
	};
	static_assert(std::is_empty_v<AllocatorPagedGH<void*, kStat_Default_Mem>>);

	template <class T, int SID>
	class AllocatorPagedLH :
		AllocatorBaseLH<SID>,
		ConstructorPagedMov<T>
	{
	public:
	};
	static_assert(std::is_empty_v<AllocatorPagedLH<void*, kStat_Default_Mem>>);

	template <typename T, int SID>
	class AllocatorPagedCC :
		AllocatorBaseLH<SID>,
		ConstructorPagedMovCC<T>
	{
	public:
	};
	static_assert(std::is_empty_v<AllocatorPagedCC<void*, kStat_Default_Mem>>);

	template <class T, int SID>
	class AllocatorPagedGH_POD :
		AllocatorBaseGH<SID>,
		ConstructorPagedPOD<T>
	{
	public:
	};
	static_assert(std::is_empty_v<AllocatorPagedGH_POD<void*, kStat_Default_Mem>>);

	template <class T, int SID>
	class AllocatorPagedLH_POD :
		AllocatorBaseLH<SID>,
		ConstructorPagedPOD<T>
	{
	public:
	};
	static_assert(std::is_empty_v<AllocatorPagedLH_POD<void*, kStat_Default_Mem>>);
}
