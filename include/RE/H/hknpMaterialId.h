#pragma once

#include "RE/H/hkHandle.h"

namespace RE
{
	class hknpMaterialIdBaseDiscriminant
	{
	public:
	};
	static_assert(std::is_empty_v<hknpMaterialIdBaseDiscriminant>);

	class hknpMaterialId :
		public hkHandle<std::uint32_t, 65535, hknpMaterialIdBaseDiscriminant>
	{
	public:
	};
	static_assert(sizeof(hknpMaterialId) == 0x04);
}
