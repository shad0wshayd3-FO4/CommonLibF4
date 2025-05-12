#pragma once

namespace RE
{
	template <class T>
	class BSTPoint3Base
	{
	public:
		T x;  // 00
		T y;  // ??
		T z;  // ??
	};

	extern template class BSTPoint3Base<std::int8_t>;
	extern template class BSTPoint3Base<std::uint8_t>;
	extern template class BSTPoint3Base<std::int16_t>;
	extern template class BSTPoint3Base<std::uint16_t>;
	extern template class BSTPoint3Base<std::int32_t>;
	extern template class BSTPoint3Base<std::uint32_t>;
	extern template class BSTPoint3Base<float>;
	extern template class BSTPoint3Base<double>;
}
