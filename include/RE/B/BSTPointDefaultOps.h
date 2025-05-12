#pragma once

namespace RE
{
	template <class T>
	class BSTPointDefaultOps
	{
	public:
	};

	extern template class BSTPointDefaultOps<std::int8_t>;
	extern template class BSTPointDefaultOps<std::uint8_t>;
	extern template class BSTPointDefaultOps<std::int16_t>;
	extern template class BSTPointDefaultOps<std::uint16_t>;
	extern template class BSTPointDefaultOps<std::int32_t>;
	extern template class BSTPointDefaultOps<std::uint32_t>;
	extern template class BSTPointDefaultOps<float>;
	extern template class BSTPointDefaultOps<double>;
}
