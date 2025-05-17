#pragma once

namespace Scaleform::Render::ContextImpl
{
	class Entry;

	class EntryChange
	{
	public:
		// members
		Entry* node;  // 00
		union
		{
			std::uint32_t changeBits;
			EntryChange*  nextFreeNode;
		};  // 08
	};
	static_assert(sizeof(EntryChange) == 0x10);
}
