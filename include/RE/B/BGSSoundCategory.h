#pragma once

#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/B/BSISoundCategory.h"

namespace RE
{
	class __declspec(novtable) BGSSoundCategory :
		public TESForm,          // 00
		public TESFullName,      // 20
		public BSISoundCategory  // 30
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSoundCategory };
		static constexpr auto VTABLE{ VTABLE::BGSSoundCategory };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kSNCT };

		// members
		BGSSoundCategory* parentCategory;       // 38
		BGSSoundCategory* sliderCategory;       // 40
		float             volumeMult;           // 48
		float             snapshotMult;         // 4C
		float             currCompressionMult;  // 50
		float             fullyCompressedMult;  // 54
		float             frequencyMult;        // 58
		float             minFrequencyMult;     // 5C
		std::uint32_t     appFlags;             // 60
		std::uint16_t     attenuation[6];       // 64
		std::uint16_t     stateFlags;           // 70
		std::uint16_t     staticMult;           // 72
		std::uint16_t     defaultMenuValue;     // 74
	};
	static_assert(sizeof(BGSSoundCategory) == 0x78);
}
