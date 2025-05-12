#pragma once

#include "RE/B/BSIReverbType.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) BGSReverbParameters :
		public TESForm,       // 00
		public BSIReverbType  // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSReverbParameters };
		static constexpr auto VTABLE{ VTABLE::BGSReverbParameters };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kREVB };

		struct ReverbParams
		{
		public:
			// members
			std::uint16_t decayTime;        // 0
			std::uint16_t hfReference;      // 2
			std::int8_t   roomFilter;       // 4
			std::int8_t   roomHFFilter;     // 5
			std::int8_t   reflections;      // 6
			std::int8_t   reverb;           // 7
			std::int8_t   decayHFRatio;     // 8
			std::int8_t   reflectionDelay;  // 9
			std::int8_t   reverbDelay;      // A
			std::int8_t   diffusionPct;     // B
			std::int8_t   densityPct;       // C
		};
		static_assert(sizeof(ReverbParams) == 0xE);

		// members
		ReverbParams  data;         // 28
		std::uint32_t reverbClass;  // 38
	};
	static_assert(sizeof(BGSReverbParameters) == 0x40);
}
