#pragma once

namespace RE
{
	template <class Mutex>
	struct BSAutoLockWriteLockPolicy
	{
	public:
		static void lock(Mutex& a_mutex) { a_mutex.lock_write(); }
		static void unlock(Mutex& a_mutex) { a_mutex.unlock_write(); }
	};

	extern template struct BSAutoLockWriteLockPolicy<BSReadWriteLock>;
}
