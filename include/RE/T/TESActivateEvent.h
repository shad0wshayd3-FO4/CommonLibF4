#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	struct TESActivateEvent
	{
		[[nodiscard]] static BSTEventSource<TESActivateEvent>* GetEventSource()
		{
			using func_t = decltype(&TESActivateEvent::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(166230) };
			return func();
		}

		// members
		NiPointer<TESObjectREFR> objectActivated;  // 00
		NiPointer<TESObjectREFR> actionRef;        // 08
	};
	static_assert(sizeof(TESActivateEvent) == 0x10);
}
