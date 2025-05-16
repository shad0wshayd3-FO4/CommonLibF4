#pragma once

#include "Scaleform/S/System.h"

namespace Scaleform::GFx
{
	class System :
		public Scaleform::System  // 0
	{
	public:
	};
	static_assert(std::is_empty_v<System>);
}
