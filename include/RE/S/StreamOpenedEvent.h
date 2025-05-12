#pragma once

namespace RE
{
	namespace BSResource::Archive2
	{
		class StreamOpenedEvent
		{
		public:
			// members
			BSFixedString streamName;     // 00
			BSFixedString sourceName;     // 08
			std::uint64_t startOffset;    // 10
			std::uint32_t sizeInArchive;  // 18
		};
		static_assert(sizeof(StreamOpenedEvent) == 0x20);
	}
}
