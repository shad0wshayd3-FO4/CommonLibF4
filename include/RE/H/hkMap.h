#pragma once

namespace RE
{
	template <class K, class V = K, class O = hkMapOperations<K>, class A = hkContainerHeapAllocator>
	class hkMap :
		public hkMapBase<K, V, O>
	{
	public:
	};
}
