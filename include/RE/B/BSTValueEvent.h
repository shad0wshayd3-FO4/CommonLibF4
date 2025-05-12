#pragma once

namespace RE
{
	template <class T>
	class BSTValueEvent
	{
	public:
		using value_type = T;

		// members
		BSTOptional<T> optionalValue;  // 00
	};
}
