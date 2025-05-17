#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class TESCellAttachDetachEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<TESCellAttachDetachEvent>* GetEventSource()
		{
			using func_t = decltype(&TESCellAttachDetachEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESCellAttachDetachEvent::GetEventSource };
			return func();
		}

		// members
		NiPointer<TESObjectREFR> refr;
		bool                     isAttaching;
	};
	static_assert(sizeof(TESCellAttachDetachEvent) == 0x10);
}
