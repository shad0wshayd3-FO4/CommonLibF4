#pragma once

namespace RE
{
	template <class T, std::uint32_t N, class Allocator = hkContainerHeapAllocator>
	class hkInplaceArrayAligned16 :
		public hkArray<T, Allocator>
	{
	public:
	private:
		std::int32_t m_padding;                            // 10
		alignas(0x10) std::byte m_storage[sizeof(T) * N];  // 20
	};
	static_assert(sizeof(hkInplaceArrayAligned16<std::uint64_t, 24>) == 0xE0);
}
