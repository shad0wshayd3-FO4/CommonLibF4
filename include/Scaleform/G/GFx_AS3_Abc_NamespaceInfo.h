#pragma once

#include "Scaleform/G/GFx_AS3_Abc_NamespaceKind.h"
#include "Scaleform/S/StringDataPtr.h"

namespace Scaleform::GFx::AS3::Abc
{
	class NamespaceInfo
	{
	public:
		// members
		NamespaceKind kind;     // 00
		StringDataPtr NameURI;  // 08
	};
	static_assert(sizeof(NamespaceInfo) == 0x18);
}
