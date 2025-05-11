#pragma once

#include "RE/Bethesda/BSScript/Object.h"
#include "RE/Bethesda/BSTPointerAndFlags.h"

namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			class AttachedScript :
				public BSTPointerAndFlags<BSTSmartPointer<Object>, 1>  // 00
			{};
			static_assert(sizeof(AttachedScript) == 0x8);
		}
	}
}
