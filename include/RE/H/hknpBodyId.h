#pragma once

#include "RE/H/hkHandle.h"

namespace RE
{
	struct hknpBodyId :
		public hkHandle<std::uint32_t, 0x7FFF'FFFF, hknpBodyIdBaseDiscriminant>
	{
	};
	static_assert(sizeof(hknpBodyId) == 0x4);
}
