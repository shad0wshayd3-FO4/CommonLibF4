#pragma once

namespace RE
{
	template <class Mutex>
	struct BSAutoLockReadLockPolicy
	{
	public:
		static void lock(Mutex& a_mutex) { a_mutex.lock_read(); }
		static void unlock(Mutex& a_mutex) { a_mutex.unlock_read(); }
	};

	extern template struct BSAutoLockReadLockPolicy<BSReadWriteLock>;
}
