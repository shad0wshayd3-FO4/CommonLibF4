#pragma once

namespace RE
{
	struct hknpMotionPropertiesId :
		public hkHandle<std::uint16_t, 0xFFFF, hknpMotionPropertiesIdBaseDiscriminant>
	{
		enum class Preset
		{
			STATIC = 0x0,     ///< No velocity allowed
			DYNAMIC = 0x1,    ///< For regular dynamic bodies, undamped and gravity factor = 1
			KEYFRAMED = 0x2,  ///< like DYNAMIC, but gravity factor = 0
			FROZEN = 0x3,     ///< like KEYFRAMED, but lots of damping
			DEBRIS = 0x4,     ///< like DYNAMIC, but aggressive deactivation

			NUM_PRESETS = 0x5
		};
	};
	static_assert(sizeof(hknpMotionPropertiesId) == 0x2);
}
