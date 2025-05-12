#pragma once

namespace RE
{
	namespace BSStorageDefs
	{
		struct StreamBuffer
		{
			std::size_t                    size;
			MemoryManager::AutoScrapBuffer buffer;
			void*                          ptrCur;
		};
	}
}
