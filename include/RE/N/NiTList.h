#pragma once

#include "RE/N/NiTDefaultAllocator.h"

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

	template <class Allocator, class T>
	class NiTListBase
	{
	public:
		class AntiBloatAllocator :
			public Allocator
		{
		public:
			// members
			std::uint32_t size;  // ??
		};

		// members
		NiTListItem<T>*    head;       // 00
		NiTListItem<T>*    tail;       // 08
		AntiBloatAllocator allocator;  // 10
	};

	template <class Allocator, class T>
	class NiTPointerListBase :
		public NiTListBase<Allocator, T>  // 00
	{
	public:
	};

	template <class T>
	class NiTList :
		public NiTPointerListBase<NiTDefaultAllocator<T>, T>  // 00
	{
	public:
	};
}
