#pragma once

namespace RE
{
	namespace BSResource
	{
		template <class T>
		class EntryQueue
		{
		public:
			// members
			BSNonReentrantSpinLock lock;  // 00
			T*                     head;  // 08
			T**                    tail;  // 10
		};
		static_assert(sizeof(EntryQueue<void>) == 0x18);
	}
}
