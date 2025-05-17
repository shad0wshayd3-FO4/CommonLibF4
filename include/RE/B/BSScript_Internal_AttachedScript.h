#pragma once

#include "RE/B/BSScript_Object.h"
#include "RE/B/BSTPointerAndFlags.h"
#include "RE/B/BSTSmartPointer.h"

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
