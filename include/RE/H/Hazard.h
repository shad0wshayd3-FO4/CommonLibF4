#pragma once

#include "RE/T/TESObjectREFR.h"

namespace RE
{
	class __declspec(novtable) Hazard :
		public TESObjectREFR  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::Hazard };
		static constexpr auto VTABLE{ VTABLE::Hazard };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kPHZD };

		// members
		void*              hazardDBHandle;  // 110 - TODO
		ActorHandle        ownerActor;      // 118
		float              age;             // 11C
		float              lifetime;        // 120
		float              targetTimer;     // 124
		float              radius;          // 128
		float              magnitude;       // 12C
		BGSHazard*         hazard;          // 130
		NiPointer<NiLight> light;           // 138
		BSSoundHandle      sound;           // 140
		std::uint32_t      flags;           // 148
	};
	static_assert(sizeof(Hazard) == 0x150);
}
