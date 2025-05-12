#pragma once

namespace RE
{
	template <class T>
	class BSTPoint2Base
	{
	public:
		T x;  // 00
		T y;  // ??
	};

	extern template class BSTPoint2Base<std::int8_t>;
	extern template class BSTPoint2Base<std::uint8_t>;
	extern template class BSTPoint2Base<std::int16_t>;
	extern template class BSTPoint2Base<std::uint16_t>;
	extern template class BSTPoint2Base<std::int32_t>;
	extern template class BSTPoint2Base<std::uint32_t>;
	extern template class BSTPoint2Base<float>;
	extern template class BSTPoint2Base<double>;
}
