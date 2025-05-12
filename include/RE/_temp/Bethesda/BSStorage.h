#pragma once

#include "RE/Bethesda/BSTSmartPointer.h"
#include "RE/Bethesda/MemoryManager.h"
namespace RE
{
	namespace BSStorageDefs
	{
		enum class ErrorCode;
		enum class SeekMode;
		struct StreamBuffer
		{
			// TODO: add funcs
			std::size_t                    size;
			MemoryManager::AutoScrapBuffer buffer;
			void*                          ptrCur;
		};
	}
}
