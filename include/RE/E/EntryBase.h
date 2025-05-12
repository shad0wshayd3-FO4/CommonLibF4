#pragma once

namespace RE
{
	namespace BSResource
	{
		class EntryBase
		{
		public:
			// members
			ID                            name;    // 00
			BSTAtomicValue<std::uint32_t> ctrl;    // 0C
			BSTSmartPointer<Stream>       stream;  // 10
		};
		static_assert(sizeof(EntryBase) == 0x18);
	}
}
