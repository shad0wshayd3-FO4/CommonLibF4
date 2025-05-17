#pragma once

#include "RE/B/BSPointerHandle.h"

namespace RE
{
	class BGSPickLockEvent
	{
	public:
		BGSPickLockEvent(TESObjectREFR* a_actor, TESObjectREFR* a_lockRef, bool a_isCrime)
		{
			ctor(a_actor, a_lockRef, a_isCrime);
		}

		[[nodiscard]] static std::uint32_t EVENT_INDEX()
		{
			static REL::Relocation<std::uint32_t*> eventIdx{ ID::BGSPickLockEvent::EventIndex };
			return *eventIdx;
		}

		// members
		ObjectRefHandle actor;       // 00
		ObjectRefHandle lockObject;  // 04
		std::uint32_t   isCrime;     // 08

	private:
		BGSPickLockEvent* ctor(TESObjectREFR* a_actor, TESObjectREFR* a_lockRef, bool a_isCrime)
		{
			using func_t = decltype(&BGSPickLockEvent::ctor);
			static REL::Relocation<func_t> func{ ID::BGSPickLockEvent::ctor };
			return func(this, a_actor, a_lockRef, a_isCrime);
		}
	};
	static_assert(sizeof(BGSPickLockEvent) == 0x0C);
}
