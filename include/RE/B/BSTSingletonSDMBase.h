#pragma once

namespace RE
{
	template <class Traits>
	struct BSTSingletonSDMBase :
		public Traits,
		public BSTSingletonSDMOpStaticBuffer<typename Traits::value_type>
	{
	public:
	};
}
