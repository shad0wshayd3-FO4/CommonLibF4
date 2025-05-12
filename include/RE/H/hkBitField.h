#pragma once

namespace RE
{
	class hkBitField
	{
	public:
		hkBitField() = default;

	private:
		hkArray<std::uint32_t> words;
		std::int32_t           numBits{ 0 };
	};
	static_assert(sizeof(hkBitField) == 0x18);
}
