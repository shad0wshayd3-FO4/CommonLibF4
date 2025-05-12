#pragma once

namespace RE
{
	template <class Allocator, class T>
	class NiTListBase
	{
	public:
		struct AntiBloatAllocator :
			public Allocator
		{
		public:
			// members
			std::uint32_t size;  // ??
		};

		// members
		NiTListItem<T>* head;       // 00
		NiTListItem<T>* tail;       // 08
		AntiBloatAllocator allocator;  // 10
	};
}
