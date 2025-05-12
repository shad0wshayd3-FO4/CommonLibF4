#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class TESHitEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<TESHitEvent>* GetEventSource()
		{
			using func_t = decltype(&TESHitEvent::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(2201886) };
			return func();
		}

		// members
		HitData                  hitData;           // 000
		NiPointer<TESObjectREFR> target;            // 0E0
		NiPointer<TESObjectREFR> cause;             // 0E8
		BSFixedString            material;          // 0F0
		std::uint32_t            sourceFormID;      // 0F8
		std::uint32_t            projectileFormID;  // 0FC
		bool                     usesHitData;       // 100
	};
	static_assert(sizeof(TESHitEvent) == 0x110);
}
