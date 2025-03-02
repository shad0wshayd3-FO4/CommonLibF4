#pragma once

#include "RE/Havok/hkBaseTypes.h"

namespace RE
{
	struct hkSlot
	{
		static constexpr auto RTTI{ RTTI::hkSlot };
		static constexpr auto VTABLE{ VTABLE::hkSlot };

		virtual ~hkSlot();

		// add
		virtual hkBool32 MatchMethod(const void* a_methodData, std::int32_t a_methodLength) const = 0;

		// members
		mutable hkSlot* next;
		void*           object;
	};

	struct hkSignal
	{
		mutable hkSlot* slots;
	};

	struct hkSignal0 : hkSignal
	{};

	template <class P0>
	struct hkSignal1 : hkSignal
	{};

	template <class P0, class P1>
	struct hkSignal2 : hkSignal
	{};

	template <class P0, class P1, class P2>
	struct hkSignal3 : hkSignal
	{};

	template <class P0, class P1, class P2, class P3>
	struct hkSignal4 : hkSignal
	{};

	template <class P0, class P1, class P2, class P3, class P4>
	struct hkSignal5 : hkSignal
	{};
}
