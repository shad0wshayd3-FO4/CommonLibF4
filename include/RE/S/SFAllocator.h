#pragma once

#include "RE/Scaleform/Kernel/SF_Memory.h"

namespace RE::Scaleform
{
	template <std::int32_t SID = kStat_Default_Mem>
	class AllocatorBaseDH
	{
	public:
	};

	template <std::int32_t SID = kStat_Default_Mem>
	class AllocatorBaseGH
	{
	public:
	};

	template <std::int32_t SID = kStat_Default_Mem>
	class AllocatorBaseLH
	{
	public:
	};

	template <class T>
	class ConstructorPOD
	{
	public:
	};

	template <class T>
	class ConstructorMov
	{
	public:
	};

	template <class T>
	class ConstructorCPP
	{
	public:
	};

	template <class T, std::int32_t SID = kStat_Default_Mem>
	struct AllocatorGH :
		public AllocatorBaseGH<SID>,  // 0
		public ConstructorMov<T>      // 1
	{
	public:
	};

	template <class T, std::int32_t SID = kStat_Default_Mem>
	struct AllocatorLH :
		public AllocatorBaseLH<SID>,  // 0
		public ConstructorMov<T>      // 1
	{
	public:
	};

	template <class T, std::int32_t SID = kStat_Default_Mem>
	struct AllocatorDH :
		public AllocatorBaseDH<SID>,  // 0
		public ConstructorMov<T>      // 1
	{
	public:
	};
}
