#pragma once

namespace RE
{
	struct PersistentPassList
	{
	public:
		// members
		BSRenderPass* head;  // 00
		BSRenderPass* tail;  // 08
	};
	static_assert(sizeof(PersistentPassList) == 0x10);
}
