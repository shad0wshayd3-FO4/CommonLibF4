#pragma once

#include "Scaleform/R/Render_Matrix.h"

namespace Scaleform::Render
{
	class ScreenToWorld
	{
	public:
		constexpr ScreenToWorld() = default;

		// members
		float    sx{ std::numeric_limits<float>::max() };     // 00
		float    sy{ std::numeric_limits<float>::max() };     // 04
		float    lastX{ std::numeric_limits<float>::max() };  // 08
		float    lastY{ std::numeric_limits<float>::max() };  // 0C
		Render::Matrix4x4<float> matProj;                                     // 10
		Render::Matrix3x4<float> matView;                                     // 50
		Render::Matrix3x4<float> matWorld;                                    // 80
		Render::Matrix4x4<float> matInvProj;                                  // B0
	};
	static_assert(sizeof(ScreenToWorld) == 0xF0);
}
