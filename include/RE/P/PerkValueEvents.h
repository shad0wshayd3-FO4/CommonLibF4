#pragma once

#include "RE/B/BSPointerHandle.h"

namespace RE
{
	class BGSPerkEntry;

	namespace PerkValueEvents
	{
		enum class Type : std::int32_t
		{
			kAdd = 0x0,
			kRemove = 0x1
		};

		class PerkValueChangedEvent
		{
		public:
			// members
			Type         changeType;  // 00
			ActorHandle  owner;       // 04
			BGSPerk*     perk;        // 08
			std::uint8_t rank;        // 10
		};
		static_assert(sizeof(PerkValueChangedEvent) == 0x18);

		class PerkEntryUpdatedEvent
		{
		public:
			// members
			ActorHandle   owner;      // 00
			BGSPerkEntry* perkEntry;  // 08
		};
		static_assert(sizeof(PerkEntryUpdatedEvent) == 0x10);
	}
}
