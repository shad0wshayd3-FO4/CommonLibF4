#pragma once

#include "RE/Scaleform/Render/Render_Matrix4x4.h"

namespace RE::Scaleform::Render
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
		Matrix4F matProj;                                     // 10
		Matrix3F matView;                                     // 50
		Matrix3F matWorld;                                    // 80
		Matrix4F matInvProj;                                  // B0
	};
	static_assert(sizeof(ScreenToWorld) == 0xF0);
}
