#pragma once

#include "RE/S/SFRenderMatrix2x4.h"
#include "RE/S/SFRenderTypes2D.h"

namespace RE::Scaleform::Render
{
	template <class T>
	class Matrix3x4Data
	{
	public:
		// members
		T m[3][4];  // 00
	};

	template <class T>
	class Matrix3x4 :
		public Matrix3x4Data<T>  // 00
	{
	public:
	};

	using Matrix3F = Matrix3x4<float>;
	static_assert(sizeof(Matrix3F) == 0x30);
}
