#pragma once

namespace RE
{
	template <
		class Key,
		class T,
		std::uint32_t N,
		class Hash = BSCRC32<Key>,
		class KeyEq = std::equal_to<Key>>
	using BSTStaticHashMap =
		BSTScatterTable<
			Hash,
			KeyEq,
			BSTScatterTableTraits<Key, T>,
			BSTStaticHashMapBase<N>::template Allocator>;
}
