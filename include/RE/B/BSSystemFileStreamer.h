#pragma once

namespace RE
{
	namespace BSSystemFileStreamer
	{
		class ID
		{
		public:
			// members
			std::uint32_t id;  // 0
		};
		static_assert(sizeof(ID) == 0x4);

		inline void UncacheAll(bool a_block)
		{
			using func_t = decltype(&UncacheAll);
			static REL::Relocation<func_t> func{ RE::ID::BSSystemFileStreamer::UncacheAll };
			return func(a_block);
		}
	}
}
