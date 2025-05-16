#pragma once

#include "RE/B/BSTSmartPointer.h"
#include "RE/B/BSSystemFileStreamer.h"
#include "RE/N/NiFile.h"

namespace RE
{
	class __declspec(novtable) BSFile :
		public NiFile  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSFile };
		static constexpr auto VTABLE{ VTABLE::BSFile };

		class PageCache;

		// members
		bool                       useAuxBuffer;         // 050
		std::byte*                 auxBuffer;            // 058
		std::int32_t               auxTrueFilePos;       // 060
		std::uint32_t              auxBufferMinIndex;    // 064
		std::uint32_t              auxBufferMaxIndex;    // 068
		char                       fileName[260];        // 06C
		std::size_t                result;               // 170
		std::size_t                ioSize;               // 178
		std::size_t                trueFilePos;          // 180
		std::size_t                fileSize;             // 188
		bool                       virtualAlloc;         // 190
		BSTSmartPointer<PageCache> pageCache;            // 198
		BSSystemFileStreamer::ID   pathID;               // 1A0
		std::uint32_t              streamerPriority;     // 1A4
		std::int8_t                basePageOffset;       // 1A8
		bool                       readThroughStreamer;  // 1A9
	};
	static_assert(sizeof(BSFile) == 0x1B0);
}
