#pragma once

#include "RE/Bethesda/CRC.h"

namespace RE
{
	template <class T, T N, class D>
	struct hkHandle
	{
		~hkHandle() noexcept {}  // intentional

		// members
		T value;  // 0
	};
}
