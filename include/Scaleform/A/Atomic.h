#pragma once

namespace Scaleform
{
	template <class T>
	class AtomicValueBase
	{
	public:
		// members
		volatile T value;  // 0
	};
	static_assert(sizeof(AtomicValueBase<std::int32_t>) == 0x04);

	template <class T>
	class AtomicInt :
		public AtomicValueBase<T>  // 0
	{
	public:
	};
	static_assert(sizeof(AtomicInt<std::int32_t>) == 0x04);
}
