#pragma once

namespace RE
{
	template <class K>
	struct hkMapOperations
	{
	};

	template <>
	struct hkMapOperations<std::int32_t>
	{
	};

	template <class K, class V = K, class O = hkMapOperations<K>>
	class hkMapBase
	{
	public:
		struct Pair
		{
			K key;
			V value;
		};

		// members
		Pair*        elem;       // 00
		std::int32_t elemCount;  // 08 - high bits are flags
		std::int32_t hashMod;    // 10 - capacity - 1
	};
	static_assert(sizeof(hkMapBase<int>) == 0x10);

	template <class K, class V = K, class O = hkMapOperations<K>, class A = hkContainerHeapAllocator>
	class hkMap :
		public hkMapBase<K, V, O>
	{
	public:
	};

	template <class K>
	struct hkMultiMapOperations
	{
	};

	template <>
	struct hkMultiMapOperations<std::int32_t>
	{
	};

	template <class K, class V = K, class O = hkMultiMapOperations<K>, class A = hkContainerHeapAllocator>
	class hkMultiMap
	{
	public:
		struct Pair
		{
			K key;
			V value;
		};

		// members
		Pair*        elem;       // 00
		std::int32_t elemCount;  // 08 - high bits are flags
		std::int32_t hashMod;    // 10 - capacity - 1
	};
	static_assert(sizeof(hkMultiMap<int>) == 0x10);
}
