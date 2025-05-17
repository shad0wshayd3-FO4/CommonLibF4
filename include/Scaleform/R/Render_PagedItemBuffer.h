#pragma once

namespace Scaleform::Render
{
	template <class C, std::int32_t N>
	class PagedItemBuffer
	{
	public:
		class Page
		{
		public:
			// members
			Page*        next;      // 00
			std::int32_t count;     // 08
			C            items[N];  // ??
		};

		// members
		Page* pages;  // 00
		Page* last;   // 08
	};
	static_assert(sizeof(PagedItemBuffer<void*, 0>) == 0x10);
}
