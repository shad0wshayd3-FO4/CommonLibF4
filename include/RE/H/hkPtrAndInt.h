#pragma once

namespace RE
{
	template <class, class, std::size_t>
	class hkPtrAndInt
	{
	public:
		// members
		std::uint64_t ptrAndInt;  // 00
	};
	static_assert(sizeof(hkPtrAndInt<void, void, 0>) == 0x08);
}
