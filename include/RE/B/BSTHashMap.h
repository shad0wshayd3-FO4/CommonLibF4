#pragma once

namespace RE
{
	template <
		class Key,
		class T,
		class Hash = BSCRC32<Key>,
		class KeyEq = std::equal_to<Key>>
	using BSTHashMap =
		BSTScatterTable<
			Hash,
			KeyEq,
			BSTScatterTableTraits<Key, T>,
			BSTScatterTableHeapAllocator>;
}
