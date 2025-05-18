#pragma once

#include "RE/H/hkHandle.h"

namespace RE
{
	class hknpMotionPropertiesIdBaseDiscriminant
	{
	public:
	};
	static_assert(std::is_empty_v<hknpMotionPropertiesIdBaseDiscriminant>);

	class hknpMotionPropertiesId :
		public hkHandle<std::uint16_t, 65535, hknpMotionPropertiesIdBaseDiscriminant>
	{
	public:
		enum class Preset;
	};
	static_assert(sizeof(hknpMotionPropertiesId) == 0x02);
}
