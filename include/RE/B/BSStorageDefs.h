#pragma once

#include "RE/M/MemoryManager.h"

namespace RE
{
	namespace BSStorageDefs
	{
		enum class ErrorCode;
		enum class SeekMode;

		struct StreamBuffer
		{
			// members
			std::size_t                    size;    // 00
			MemoryManager::AutoScrapBuffer buffer;  // 08
			void*                          ptrCur;  // 10
		};
		static_assert(sizeof(StreamBuffer) == 0x18);
	}
}
