#pragma once

namespace RE
{
	struct TESDeathEvent
	{
		[[nodiscard]] static BSTEventSource<TESDeathEvent>* GetEventSource()
		{
			using func_t = decltype(&TESDeathEvent::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(2201833) };
			return func();
		}

		// members
		NiPointer<TESObjectREFR> actorDying;   // 00
		NiPointer<TESObjectREFR> actorKiller;  // 08
		bool                     dead;         // 10
	};
	static_assert(sizeof(TESDeathEvent) == 0x18);
}
