#pragma once

namespace RE
{
	struct CrimeGoldStruct
	{
	public:
		// members
		std::uint32_t violent;                     // 00
		std::uint32_t nonViolent;                  // 04
		std::uint32_t totalNonViolentAccumulated;  // 08
		std::uint32_t totalViolentAccumulated;     // 0C
	};
	static_assert(sizeof(CrimeGoldStruct) == 0x10);
}
