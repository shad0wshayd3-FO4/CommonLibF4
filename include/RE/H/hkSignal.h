#pragma once

namespace RE
{
	struct hkSignal
	{
		mutable hkSlot* slots;
	};

	struct hkSignal0 : hkSignal
	{
	};

	template <class P0>
	struct hkSignal1 : hkSignal
	{
	};

	template <class P0, class P1>
	struct hkSignal2 : hkSignal
	{
	};

	template <class P0, class P1, class P2>
	struct hkSignal3 : hkSignal
	{
	};

	template <class P0, class P1, class P2, class P3>
	struct hkSignal4 : hkSignal
	{
	};

	template <class P0, class P1, class P2, class P3, class P4>
	struct hkSignal5 : hkSignal
	{
	};
}
