#pragma once

namespace RE
{
	template <class T>
	class NiTListItem
	{
	public:
		NiTListItem* next;     // 00
		NiTListItem* prev;     // 08
		T            element;  // 10
	};
}
