#pragma once

#include "RE/B/BSTranslator.h"
#include "Scaleform/G/GFX_Translator.h"

namespace RE
{
	class __declspec(novtable) BSScaleformTranslator :
		public Scaleform::GFx::Translator
	{
	public:
		// members
		BSTranslator translator;  //20
	};
	static_assert(sizeof(BSScaleformTranslator) == 0x50);
}
