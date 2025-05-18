#include "RE/B/BSSpring_SpringState.h"

namespace RE
{
	namespace BSSpring
	{
		template class SpringState<float>;
		static_assert(sizeof(SpringState<float>) == 0xC);

		template class SpringState<NiPoint2>;
		static_assert(sizeof(SpringState<NiPoint2>) == 0x14);

		template class SpringState<NiPoint3>;
		static_assert(sizeof(SpringState<NiPoint3>) == 0x1C);
	}
}
