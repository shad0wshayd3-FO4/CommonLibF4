#pragma once

namespace RE
{
	template <
		class T,
		class Ops = BSTPointDefaultOps<T>>
		class BSTPoint2 :
		public BSTPoint2Base<T>,
		public BSTPointDefaultOps<T>
	{
	public:
	};

	extern template class BSTPoint2<std::int8_t>;
	extern template class BSTPoint2<std::uint8_t>;
	extern template class BSTPoint2<std::int16_t>;
	extern template class BSTPoint2<std::uint16_t>;
	extern template class BSTPoint2<std::int32_t>;
	extern template class BSTPoint2<std::uint32_t>;
	extern template class BSTPoint2<float>;
	extern template class BSTPoint2<double>;
}
