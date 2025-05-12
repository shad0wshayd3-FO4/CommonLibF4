#pragma once

namespace RE
{
	class __declspec(novtable) IMemoryStoreBase
	{
	public:
		static constexpr auto RTTI{ RTTI::IMemoryStoreBase };
		static constexpr auto VTABLE{ VTABLE::IMemoryStoreBase };

		virtual ~IMemoryStoreBase() = default;  // 00

		// add
		virtual std::size_t Size(void const* a_mem) const = 0;                 // 01
		virtual void        GetMemoryStats(MemoryStats* a_stats) = 0;          // 02
		virtual bool        ContainsBlockImpl(const void* a_block) const = 0;  // 03
	};
	static_assert(sizeof(IMemoryStoreBase) == 0x8);
}
