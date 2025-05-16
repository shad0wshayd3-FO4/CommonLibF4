#pragma once

#include "RE/B/BSIAudioEffectChain.h"
#include "RE/B/BSTArray.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BSIAudioEffectParameters;

	class __declspec(novtable) BGSAudioEffectChain :
		public TESForm,             // 00
		public BSIAudioEffectChain  // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSAudioEffectChain };
		static constexpr auto VTABLE{ VTABLE::BGSAudioEffectChain };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kAECH };

		// members
		BSTArray<BSIAudioEffectParameters*> effects;  // 28
	};
	static_assert(sizeof(BGSAudioEffectChain) == 0x40);
}
