#pragma once

namespace RE
{
	template <class T, std::uint32_t N, class Allocator = hkContainerHeapAllocator>
	class hkInplaceArray :
		public hkArray<T, Allocator>  // 00
	{
	public:
	private:
		T m_storage[N];  // 10
	};
}
