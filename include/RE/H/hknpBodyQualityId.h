#pragma once

#include "RE/H/hkHandle.h"

namespace RE
{
	struct hknpBodyQualityId :
		public hkHandle<std::uint8_t, 0xFF, hknpBodyQualityIdBaseDiscriminant>
	{
	};
	static_assert(sizeof(hknpBodyQualityId) == 0x1);
}
