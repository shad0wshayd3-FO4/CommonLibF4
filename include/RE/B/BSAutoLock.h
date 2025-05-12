#pragma once

namespace RE
{
	template <class Mutex, template <class> class Policy = BSAutoLockDefaultPolicy>
	class BSAutoLock
	{
	public:
		using mutex_type = Mutex;
		using policy_type = Policy<mutex_type>;

		explicit BSAutoLock(mutex_type& a_mutex) :
			_lock(std::addressof(a_mutex))
		{
			policy_type::lock(*_lock);
		}

		explicit BSAutoLock(mutex_type* a_mutex) :
			_lock(a_mutex)
		{
			if (_lock) {
				policy_type::lock(*_lock);
			}
		}

		~BSAutoLock()
		{
			if (_lock) {
				policy_type::unlock(*_lock);
			}
		}

	private:
		// members
		mutex_type* _lock{ nullptr };  // 00
	};

	template <class Mutex>
	BSAutoLock(Mutex&) -> BSAutoLock<Mutex>;

	template <class Mutex>
	BSAutoLock(Mutex*) -> BSAutoLock<Mutex>;

	extern template class BSAutoLock<BSSpinLock, BSAutoLockDefaultPolicy>;
	extern template class BSAutoLock<BSReadWriteLock, BSAutoLockReadLockPolicy>;
	extern template class BSAutoLock<BSReadWriteLock, BSAutoLockWriteLockPolicy>;

	using BSAutoReadLock = BSAutoLock<BSReadWriteLock, BSAutoLockReadLockPolicy>;
	using BSAutoWriteLock = BSAutoLock<BSReadWriteLock, BSAutoLockWriteLockPolicy>;
}
