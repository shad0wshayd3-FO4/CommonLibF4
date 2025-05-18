#pragma once

#include "RE/H/hkPtrAndInt.h"
#include "RE/H/hkSlot.h"

namespace RE
{
	class hkSignal
	{
	public:
		// members
		hkPtrAndInt<hkSlot, std::uint32_t, 3> slots;  // 00
	};
	static_assert(sizeof(hkSignal) == 0x08);

	class hkSignal0 :
		public hkSignal
	{
	public:
	};
	static_assert(sizeof(hkSignal0) == 0x08);

	template <class T>
	class hkSignal1 :
		public hkSignal
	{
	public:
	};
	static_assert(sizeof(hkSignal1<void>) == 0x08);

	template <class T, class U>
	class hkSignal2 :
		public hkSignal
	{
	public:
	};
	static_assert(sizeof(hkSignal2<void, void>) == 0x08);

	template <class T, class U, class V>
	class hkSignal3 :
		public hkSignal
	{
	public:
	};
	static_assert(sizeof(hkSignal3<void, void, void>) == 0x08);
}
