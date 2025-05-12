#pragma once

namespace RE
{
	inline void NiFree(void* a_ptr)
	{
		using func_t = decltype(&NiFree);
		static REL::Relocation<func_t> func{ REL::ID(242362) };
		return func(a_ptr);
	}

	inline void* NiMalloc(std::size_t a_num)
	{
		using func_t = decltype(&NiMalloc);
		static REL::Relocation<func_t> func{ REL::ID(974443) };
		return func(a_num);
	}
}
