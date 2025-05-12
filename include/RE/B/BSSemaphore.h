#pragma once

namespace RE
{
	class BSSemaphore :
		public BSSemaphoreBase
	{
	public:
	};
	static_assert(sizeof(BSSemaphore) == 0x08);
}
