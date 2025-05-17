#pragma once

namespace RE
{
	class BSRenderPass;

	class PersistentPassList
	{
	public:
		// members
		BSRenderPass* head;  // 00
		BSRenderPass* tail;  // 08
	};
	static_assert(sizeof(PersistentPassList) == 0x10);
}
