#pragma once

#include "RE/I/ImageSpaceModifierInstanceTemp.h"

namespace RE
{
	class ImageSpaceModifierInstanceDOF :
		public ImageSpaceModifierInstanceTemp  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceModifierInstanceDOF };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceModifierInstanceDOF };

		enum class DepthOfFieldMode
		{
			kFrontBack = 0,
			kFront,
			kBack,
			kNone,
		};

		virtual ~ImageSpaceModifierInstanceDOF();  // 00

		// override (ImageSpaceModifierInstanceTemp)
		virtual void Apply() override;                    // 29
		virtual void PrintInfo(char* a_buffer) override;  // 2A

		static ImageSpaceModifierInstanceDOF* Trigger(
			float            a_distance,
			float            a_range,
			float            a_vignetteRadius,
			float            a_vignetteStrength,
			DepthOfFieldMode a_mode,
			float            a_strength,
			float            a_duration)
		{
			using func_t = decltype(&ImageSpaceModifierInstanceDOF::Trigger);
			static REL::Relocation<func_t> func{ REL::ID(2199922) };
			return func(a_distance, a_range, a_vignetteRadius, a_vignetteStrength, a_mode, a_strength, a_duration);
		}

		// members
		ImageSpaceModData data;  // 30
	};
	static_assert(sizeof(ImageSpaceModifierInstanceDOF) == 0x80);
}
