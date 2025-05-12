#pragma once

namespace RE
{
    template <class Key>
	class BSTSetTraits
	{
	public:
		using key_type = Key;
		using mapped_type = void;
		using value_type = key_type;

		[[nodiscard]] static const key_type& unwrap_key(const value_type& a_value) noexcept { return a_value; }
	};
}
