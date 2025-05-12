#pragma once

namespace RE
{
	template <class Key, class T>
	class BSTScatterTableTraits
	{
	public:
		using key_type = Key;
		using mapped_type = T;
		using value_type = RE::BSTTuple<const key_type, mapped_type>;

		[[nodiscard]] static const key_type& unwrap_key(const value_type& a_value) noexcept { return a_value.first; }
	};
}
