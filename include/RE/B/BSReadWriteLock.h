#pragma once

namespace RE
{
	class BSReadWriteLock
	{
	public:
		void lock_read()
		{
			using func_t = decltype(&BSReadWriteLock::lock_read);
			static REL::Relocation<func_t> func{ REL::ID(2267897) };
			return func(this);
		}

		void lock_write()
		{
			using func_t = decltype(&BSReadWriteLock::lock_write);
			static REL::Relocation<func_t> func{ REL::ID(2267898) };
			return func(this);
		}

		[[nodiscard]] bool try_lock_read()
		{
			using func_t = decltype(&BSReadWriteLock::try_lock_read);
			static REL::Relocation<func_t> func{ REL::ID(2267901) };
			return func(this);
		}

		[[nodiscard]] bool try_lock_write()
		{
			using func_t = decltype(&BSReadWriteLock::try_lock_write);
			static REL::Relocation<func_t> func{ REL::ID(2267902) };
			return func(this);
		}

		void unlock_read()
		{
			stl::atomic_ref lock{ _lock };
			--lock;
		}

		void unlock_write()
		{
			stl::atomic_ref lock{ _lock };
			if (_lock == 0x80000001) {
				_writerThread = 0;
				lock.exchange(0);
			}
			else {
				--lock;
			}
		}

	private:
		// members
		std::uint32_t          _writerThread{ 0 };  // 0
		volatile std::uint32_t _lock{ 0 };          // 4
	};
	static_assert(sizeof(BSReadWriteLock) == 0x8);
}
