#pragma once

#include "Scaleform/N/NewOverrideBase.h"

namespace Scaleform::GFx::AS3::Abc
{
	class MetadataTable :
		public NewOverrideBase<338>
	{
	public:
		// members
		std::byte pad[0x18];  // 00
	};
	static_assert(sizeof(MetadataTable) == 0x18);
}
