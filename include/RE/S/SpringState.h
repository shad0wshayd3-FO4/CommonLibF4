#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	namespace BSSpring
	{
		template <class T>
		class SpringState
		{
		public:
			// members
			T     position;        // 00
			T     velocity;        // ??
			float springConstant;  // ??
		};

		extern template class SpringState<float>;
		extern template class SpringState<NiPoint2>;
		extern template class SpringState<NiPoint3>;
	}
}
