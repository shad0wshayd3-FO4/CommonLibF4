#pragma once

namespace RE
{
	template <class Key, class T>
	class NiTMapItem
	{
	public:
		using key_type = Key;
		using mapped_type = T;

		F4_HEAP_REDEFINE_NEW(NiTMapItem);

		// members
		NiTMapItem* next;    // 00
		key_type    first;   // 08
		mapped_type second;  // ??
	};
}
