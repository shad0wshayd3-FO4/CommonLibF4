#pragma once

#include "RE/Havok/hkArray.h"

namespace RE
{
	class hkBlockStreamAllocator;

	namespace hkBlockStreamBase
	{
		struct Block;

		class Stream
		{
		public:
			// members
			hkBlockStreamAllocator*             allocator;                              // 00
			std::int32_t                        numTotalElements;                       // 08
			Stream*                             blockStreamPpu;                         // 10
			hkBool                              partiallyFreed;                         // 18
			hkBool                              zeroNewBlocks;                          // 19
			hkBool                              isLocked;                               // 1A
			hkBool                              spuWronglySentConsumedBlockStreamBack;  // 1B
			hkInplaceArrayAligned16<Block*, 24> blocks;                                 // 20
		};
		static_assert(sizeof(hkBlockStreamBase::Stream) == 0x100);
	}

	template <class T>
	class hkBlockStream :
		public hkBlockStreamBase::Stream  // 00
	{
	public:
		class Consumer;
		class Modifier;
		class Reader;
		class Writer;
	};
}
