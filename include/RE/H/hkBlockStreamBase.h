#pragma once

#include "RE/H/hkArray.h"
#include "RE/H/hkBool.h"

namespace RE
{
	class hkBlockStreamAllocator;

	class hkBlockStreamBase
	{
	public:
		class Stream;

		class Block
		{
		public:
			// members
			std::uint32_t           numElementsAndBytesUsed;  // 00
			std::int32_t            blockIndexInStream;       // 04
			Block*                  next;                     // 08
			hkBlockStreamAllocator* allocator;                // 10
			Stream*                 blockStream;              // 18
			std::byte               data[4064];               // 20
		};
		static_assert(sizeof(Block) == 0x1000);

		class Stream
		{
		public:
			// members
			hkBlockStreamAllocator*             allocator;                              // 00
			std::int32_t                        numTotalElements;                       // 08
			Stream*                             blockStreamPPU;                         // 10
			hkBool                              partiallyFreed;                         // 18
			hkBool                              zeroNewBlocks;                          // 19
			hkBool                              isLocked;                               // 1A
			hkBool                              spuWronglySentConsumedBlockStreamBack;  // 1B
			hkInplaceArrayAligned16<Block*, 24> blocks;                                 // 20
		};
		static_assert(sizeof(Stream) == 0x100);
	};
	static_assert(std::is_empty_v<hkBlockStreamBase>);
}
