#pragma once

namespace RE
{
	class hkSimdFloat32
	{
	public:
		// members
		__m128 real;  // 00
	};
	static_assert(sizeof(hkSimdFloat32) == 0x10);
}
