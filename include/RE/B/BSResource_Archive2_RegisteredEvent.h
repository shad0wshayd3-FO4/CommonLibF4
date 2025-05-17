#pragma once

#include "RE/B/BSResource_Archive2_DataReader.h"
#include "RE/B/BSResource_ID.h"

namespace RE::BSResource
{
	namespace Archive2
	{
		class RegisteredEvent
		{
		public:
			// members
			DataReader    reader;          // 00
			ID            nameID;          // 20
			const char*   nameText;        // 30
			std::uint32_t contentsFormat;  // 38
			std::uint32_t fileCount;       // 3C
		};
		static_assert(sizeof(RegisteredEvent) == 0x40);
	}
}
