#pragma once

namespace RE
{
	class hkBool
	{
	public:
		// members
		bool _bool;  // 00
	};
	static_assert(sizeof(hkBool) == 0x01);

	using hkBool32 = std::uint32_t;
	using hkBoolLL = std::uint64_t;
}
