#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	struct TESMagicEffectApplyEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<TESMagicEffectApplyEvent>* GetEventSource()
		{
			using func_t = decltype(&TESMagicEffectApplyEvent::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(1327824) };
			return func();
		}

		// members
		NiPointer<TESObjectREFR> target;             // 00
		NiPointer<TESObjectREFR> caster;             // 08
		std::uint32_t            magicEffectFormID;  // 10
	};
	static_assert(sizeof(TESMagicEffectApplyEvent) == 0x18);
}
