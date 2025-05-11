#pragma once

#include "RE/Bethesda/BSContainer.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSScript/IMemoryPagePolicy.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/BSTHashMap.h"
#include "RE/Bethesda/BSTObjectArena.h"
#include "RE/Bethesda/BSTSmartPointer.h"
#include "RE/Bethesda/BSTTuple.h"
#include "RE/Bethesda/MemoryManager.h"

namespace RE
{
	namespace BSScript
	{
		class MemoryPage;  // stub

		struct IMemoryPagePolicy;

		class __declspec(novtable) SimpleAllocMemoryPagePolicy :
			public IMemoryPagePolicy
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__SimpleAllocMemoryPagePolicy };
			static constexpr auto VTABLE{ VTABLE::BSScript__SimpleAllocMemoryPagePolicy };

			// override (IMemoryPagePolicy)
			std::uint32_t    MaximumPageSize() const override { return maxPageSize; }                                                                // 01
			std::uint32_t    MaximumStackDepth() const override { return maxStackDepth; }                                                            // 02
			AllocationStatus AllocatePage(std::uint32_t a_sizeInBytes, NewPageStrategy a_strategy, BSTAutoPointer<MemoryPage>& a_newPage) override;  // 03
			AllocationStatus GetLargestAvailablePage(BSTAutoPointer<MemoryPage>& a_newPage) override;                                                // 04
			void             DisposePage(BSTAutoPointer<MemoryPage>& a_oldPage) override;                                                            // 05

			// members
			const std::uint32_t minPageSize{ 0x80 };            // 08
			const std::uint32_t maxPageSize{ 0x200 };           // 0C
			const std::uint32_t maxAllocatedMemory{ 0x25800 };  // 10
			const std::uint32_t maxStackDepth{ 0x64 };          // 14
			bool                ignoreMemoryLimit;              // 18
			bool                outOfMemory;                    // 19
			BSSpinLock          dataLock;                       // 1C
			std::uint32_t       currentMemorySize;              // 24
			std::uint32_t       maxAdditionalAllocations;       // 28
		};
		static_assert(sizeof(SimpleAllocMemoryPagePolicy) == 0x30);
	}
}
