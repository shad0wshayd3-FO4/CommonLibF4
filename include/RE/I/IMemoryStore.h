#pragma once

namespace RE
{
	class __declspec(novtable) IMemoryStore :
		public IMemoryStoreBase  // 0
	{
	public:
		static constexpr auto RTTI{ RTTI::IMemoryStore };
		static constexpr auto VTABLE{ VTABLE::IMemoryStore };

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~IMemoryStore() = default;  // 00

		// add
		virtual void* AllocateAlignImpl(std::size_t a_size, std::uint32_t a_alignment) = 0;                                                 // 04
		virtual void  DeallocateAlignImpl(void*& a_block) = 0;                                                                              // 05
		virtual void* TryAllocateImpl([[maybe_unused]] std::size_t a_size, [[maybe_unused]] std::uint32_t a_alignment) { return nullptr; }  // 06
	};
	static_assert(sizeof(IMemoryStore) == 0x8);
}
