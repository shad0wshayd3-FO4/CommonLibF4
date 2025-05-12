#pragma once

namespace RE
{
	struct StolenItemValueStruct
	{
	public:
		// members
		std::uint32_t stolenItemValueNoCrime;  // 0
		std::uint32_t istolenItemValueCrime;   // 4
	};
	static_assert(sizeof(StolenItemValueStruct) == 0x8);
}
