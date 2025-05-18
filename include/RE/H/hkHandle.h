#pragma once

namespace RE
{
	template <class T, std::size_t N, class>
	class hkHandle
	{
	public:
		// members
		T value;  // 00
	};
	static_assert(sizeof(hkHandle<std::uint8_t, 255, void>) == 0x01);
}
