#pragma once

namespace RE
{
	class BSSemaphoreBase
	{
	public:
		// members
		void* semaphore;  // 00
	};
	static_assert(sizeof(BSSemaphoreBase) == 0x08);

	class BSSemaphore :
		public BSSemaphoreBase
	{
	public:
	};
	static_assert(sizeof(BSSemaphore) == 0x08);
}
