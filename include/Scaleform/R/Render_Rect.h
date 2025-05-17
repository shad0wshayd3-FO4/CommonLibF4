#pragma once

namespace Scaleform::Render
{
	template <class T>
	class RectData
	{
	public:
		// members
		T x1;  // 00
		T y1;  // ??
		T x2;  // ??
		T y2;  // ??
	};

	template <class T>
	class Rect :
		public RectData<T>  // 00
	{
	public:
	};
}
