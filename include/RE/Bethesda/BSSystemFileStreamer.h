#pragma once

namespace RE::BSSystemFileStreamer
{
	inline void UncacheAll(bool a_block)
	{
		using func_t = decltype(&UncacheAll);
		static REL::Relocation<func_t> func{ REL::ID(2268797) };
		return func(a_block);
	}
}
