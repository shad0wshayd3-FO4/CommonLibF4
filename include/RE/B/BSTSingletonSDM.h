#pragma once

namespace RE
{
#ifdef __EDG__

	template <class T, template <class> class Buffer = BSTSingletonSDMOpStaticBuffer>
	struct BSTSingletonSDM
	{
	public:
		std::uint8_t padding;
	};

#else

	template <class T, template <class> class Buffer = BSTSingletonSDMOpStaticBuffer>
	struct BSTSingletonSDM :
		public BSTSingletonSDMBase<BSTSDMTraits<T, Buffer<T>>>
	{
	public:
		using value_type = T;
	};

#endif
}
