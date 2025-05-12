#pragma once

#include "RE/S/SFRenderMatrix2x4.h"
#include "RE/S/SFRenderMatrix3x4.h"
#include "RE/S/SFRenderTypes2D.h"

namespace RE::Scaleform::Render
{
	template <class T>
	class Matrix4x4Data
	{
	public:
		// members
		T m[4][4];  // 00
	};

	template <class T>
	class Matrix4x4 :
		public Matrix4x4Data<T>  // 00
	{
	public:
	};

	using Matrix4F = Matrix4x4<float>;
	static_assert(sizeof(Matrix4F) == 0x40);
}
