#pragma once

#include "RE/H/hkMemoryAllocator.h"

namespace RE
{
	struct hkContainerHeapAllocator
	{
		struct __declspec(novtable) Allocator :
			public hkMemoryAllocator
		{
			static constexpr auto RTTI{ RTTI::hkContainerHeapAllocator__Allocator };
			static constexpr auto VTABLE{ VTABLE::hkContainerHeapAllocator__Allocator };

			~Allocator() override;

			// override (hkMemoryAllocator)
			virtual void*        BlockAlloc(std::int32_t a_numBytes) override;                                 // 01
			virtual void         BlockFree(void* a_ptr, std::int32_t a_numBytes) override;                     // 02
			virtual void*        BufAlloc(std::int32_t& a_reqNumBytesInOut) override;                          // 03
			virtual void         BufFree(void* a_ptr, std::int32_t a_numBytes) override;                       // 04
			virtual void         GetMemoryStatistics(MemoryStatistics& a_usage) const override;                // 08
			virtual std::int32_t GetAllocatedSize(const void* a_obj, std::int32_t a_numBytes) const override;  // 09
		};
		static_assert(sizeof(Allocator) == 0x8);

		[[nodiscard]] static Allocator* GetSingleton()
		{
			static REL::Relocation<hkContainerHeapAllocator::Allocator*> singleton{ REL::ID(2665426) };
			return singleton.get();
		}
	};
	static_assert(sizeof(hkContainerHeapAllocator) == 0x1);
}
