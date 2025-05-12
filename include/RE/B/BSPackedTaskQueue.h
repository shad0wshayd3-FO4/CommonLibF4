#pragma once

namespace RE
{
	class BSPackedTaskQueue
	{
	public:
		// members
		BSTCommonScrapHeapMessageQueue<BSPackedTask> queue;  // 00
		void (*UnpackFunc_t)(const BSPackedTask&);           // 28
	};
	static_assert(sizeof(BSPackedTaskQueue) == 0x30);
}
