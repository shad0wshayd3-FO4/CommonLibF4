#pragma once

#include "RE/I/IMemoryStore.h"

namespace RE
{
	class __declspec(novtable) IMemoryHeap :
		public IMemoryStore  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::IMemoryHeap };
		static constexpr auto VTABLE{ VTABLE::IMemoryHeap };

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~IMemoryHeap() = default;

		// override (IMemoryStore)
		bool  ContainsBlockImpl(const void* a_block) const override { return PointerInHeap(a_block); }                             // 03
		void* AllocateAlignImpl(std::size_t a_size, std::uint32_t a_alignment) override { return Allocate(a_size, a_alignment); }  // 04
		void  DeallocateAlignImpl(void*& a_block) override { Deallocate(a_block, 0); }                                             // 05

		// add
		virtual const char*   GetName() const = 0;                                                      // 07
		virtual void*         Allocate(std::size_t a_size, std::uint32_t a_alignment) = 0;              // 08
		virtual void          Deallocate(void* a_mem, std::uint32_t) = 0;                               // 09
		virtual bool          PointerInHeap(const void* a_pointer) const = 0;                           // 0A
		virtual std::size_t   TotalSize(const void* a_pointer) const = 0;                               // 0B
		virtual void          GetHeapStats(HeapStats* a_stats, bool a_fullBlockInfo) = 0;               // 0C
		virtual bool          ShouldTrySmallBlockPools(std::size_t a_size, MEM_CONTEXT a_context) = 0;  // 0D
		virtual std::uint32_t GetPageSize() const = 0;                                                  // 0E
	};
	static_assert(sizeof(IMemoryHeap) == 0x8);
}
