#include "RE/B/BSTInterpolator.h"

namespace RE
{
	template class BSTInterpolator<float, EaseOutInterpolator, GetCurrentPositionFunctor>;
	static_assert(sizeof(BSTInterpolator<float, EaseOutInterpolator, GetCurrentPositionFunctor>) == 0x18);
}
