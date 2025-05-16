#pragma once

#include "Scaleform/F/Flags.h"
#include "Scaleform/G/GFx_State.h"

namespace Scaleform::GFx
{
	class __declspec(novtable) Translator :
		public State
	{
	public:
		enum class WordWrappingType : std::uint32_t
		{
			kDefault = 0,
			kAsian = 1 << 0,
			kProhibition = 1 << 1,
			kNoHangulWrap = 1 << 2,
			kHyphenation = 1 << 3,
			kCustom = 0x80
		};

		Translator() :
			State(StateType::kTranslator)
		{}

		explicit Translator(Flags<WordWrappingType> a_wwMode) :
			State(StateType::kTranslator), wwMode(a_wwMode)
		{}

		// members
		Flags<WordWrappingType> wwMode;  // 18
	};
	static_assert(sizeof(Translator) == 0x20);
}
