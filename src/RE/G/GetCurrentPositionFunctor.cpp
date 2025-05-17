#include "RE/G/GetCurrentPositionFunctor.h"

namespace RE
{
	template class GetCurrentPositionFunctor<float>;
	static_assert(std::is_empty_v<GetCurrentPositionFunctor<float>>);
}
