#pragma once

#include "Scaleform/G/GFx_AS3_Abc_NamespaceInfo.h"
#include "Scaleform/N/NewOverrideBase.h"

namespace Scaleform::GFx::AS3::Abc
{
	class ConstPool :
		public NewOverrideBase<339>
	{
	public:
		// members
		std::uint32_t       doubleCount;         // 00
		const std::uint8_t* doubles;             // 08
		std::byte           pad10[0xA0 - 0x10];  // 10
		const NamespaceInfo anyNamespace;        // A0
	};
	static_assert(sizeof(ConstPool) == 0xB8);
}
