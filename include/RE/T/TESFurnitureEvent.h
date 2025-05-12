#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	struct TESFurnitureEvent
	{
		enum class FurnitureEventType : std::int32_t
		{
			kEnter = 0x0,
			kExit = 0x1
		};

		[[nodiscard]] static BSTEventSource<TESFurnitureEvent>* GetEventSource()
		{
			using func_t = decltype(&TESFurnitureEvent::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(2201844) };
			return func();
		}

		[[nodiscard]] constexpr bool IsEnter() const noexcept { return type.all(FurnitureEventType::kEnter); }
		[[nodiscard]] constexpr bool IsExit() const noexcept { return type.all(FurnitureEventType::kExit); }

		// members
		NiPointer<TESObjectREFR>                       actor;            // 00
		NiPointer<TESObjectREFR>                       targetFurniture;  // 08
		REX::EnumSet<FurnitureEventType, std::int32_t> type;             // 10
	};
	static_assert(sizeof(TESFurnitureEvent) == 0x18);
}
