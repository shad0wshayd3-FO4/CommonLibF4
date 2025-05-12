#pragma once

namespace RE
{
	namespace BSSpring
	{
		template <class T>
		struct SpringState
		{
		public:
			// members
			T     position;        // 00
			T     velocity;        // ??
			float springConstant;  // ??
		};

		extern template struct SpringState<float>;
		extern template struct SpringState<NiPoint2>;
		extern template struct SpringState<NiPoint3>;
	}
}
