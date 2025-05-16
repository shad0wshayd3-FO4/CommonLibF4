#pragma once

namespace Scaleform::Render
{
	template <class T>
	class Matrix2x4Data
	{
	public:
		// members
		T m[2][4];  // 00
	};

	template <class T>
	class Matrix2x4 :
		public Matrix2x4Data<T>  // 00
	{
	public:
	};
}

namespace Scaleform::Render
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
}

namespace Scaleform::Render
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
}
