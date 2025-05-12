#pragma once

namespace RE
{
	template <class Mutex>
	struct BSAutoLockDefaultPolicy
	{
	public:
		static void lock(Mutex& a_mutex) { a_mutex.lock(); }
		static void unlock(Mutex& a_mutex) { a_mutex.unlock(); }
	};

	extern template struct BSAutoLockDefaultPolicy<BSSpinLock>;
}
