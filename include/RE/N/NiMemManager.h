#pragma once

namespace RE
{
	inline void NiFree(void* a_ptr)
	{
		using func_t = decltype(&NiFree);
		static REL::Relocation<func_t> func{ ID::NiFree };
		return func(a_ptr);
	}

	inline void* NiMalloc(std::size_t a_num)
	{
		using func_t = decltype(&NiMalloc);
		static REL::Relocation<func_t> func{ ID::NiMalloc };
		return func(a_num);
	}

	template <class T>
	class NiTMallocInterface
	{
	public:
		[[nodiscard]] static T* allocate(std::size_t a_num) { return NiMalloc(sizeof(T) * a_num); }
		static void             deallocate(T* a_ptr) { NiFree(a_ptr); }
	};

	template <class T>
	class NiTNewInterface
	{
	public:
		[[nodiscard]] static T* allocate(std::size_t a_num) { return new T[a_num]; }
		static void             deallocate(T* a_ptr) { delete[] a_ptr; }
	};
}
