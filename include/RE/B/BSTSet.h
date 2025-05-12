#pragma once

namespace RE
{
    template <
		class Key,
		class Hash = BSCRC32<Key>,
		class KeyEq = std::equal_to<Key>>
	using BSTSet =
		BSTScatterTable<
			Hash,
			KeyEq,
			BSTSetTraits<Key>,
			BSTScatterTableHeapAllocator>;
}
