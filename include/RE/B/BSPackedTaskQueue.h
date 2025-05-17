#pragma once

#include "RE/B/BSTMessageQueue.h"

namespace RE
{
	class BSPackedTask;

	class BSPackedTaskQueue
	{
	public:
		using UnpackFunc_t = void(*)(const BSPackedTask&);

		// members
		BSTCommonScrapHeapMessageQueue<BSPackedTask> queue;       // 00
		UnpackFunc_t*                                unpackFunc;  // 28
	};
	static_assert(sizeof(BSPackedTaskQueue) == 0x30);
}
