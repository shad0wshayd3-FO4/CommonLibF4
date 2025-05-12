#pragma once

namespace RE
{
	template <
		class T,
		class Ops = BSTPointDefaultOps<T>>
	class BSTPoint3 :
		public BSTPoint3Base<T>,
		public BSTPointDefaultOps<T>
	{
	public:
	};

	extern template class BSTPoint3<std::int8_t>;
	extern template class BSTPoint3<std::uint8_t>;
	extern template class BSTPoint3<std::int16_t>;
	extern template class BSTPoint3<std::uint16_t>;
	extern template class BSTPoint3<std::int32_t>;
	extern template class BSTPoint3<std::uint32_t>;
	extern template class BSTPoint3<float>;
	extern template class BSTPoint3<double>;
}
