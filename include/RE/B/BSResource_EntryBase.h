#pragma once

#include "RE/B/BSTSmartPointer.h"
#include "RE/B/BSTAtomicValue.h"
#include "RE/B/BSResource_ID.h"
#include "RE/B/BSResource_Stream.h"

namespace RE::BSResource
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
