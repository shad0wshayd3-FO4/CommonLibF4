#pragma once

#include "RE/U/UIShaderColors.h"

namespace RE
{
	struct alignas(0x10) UIShaderFXInfo
	{
	public:
		// members
		NiRect<float>  renderQuad;  // 00
		UIShaderColors shaderFX;    // 10
	};
	static_assert(sizeof(UIShaderFXInfo) == 0x50);
}
