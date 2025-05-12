#pragma once

namespace RE
{
	template <
		class T,
		class Interpolator,
		template <class> class GetCurrent>
	class BSTInterpolator
	{
	public:
		Interpolator  interpolate;  // 00
		GetCurrent<T> getCurr;      // ??
		T             start;        // ??
		T             finish;       // ??
		float         duration;     // ??
		float         startTime;    // ??
		bool          finished;     // ??
	};

	extern template class BSTInterpolator<float, EaseOutInterpolator, GetCurrentPositionFunctor>;
}
