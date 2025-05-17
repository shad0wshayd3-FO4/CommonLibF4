#pragma once

#include "RE/N/NiColor.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiPointer.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESTexture.h"
#include "RE/W/WaterShaderData.h"

namespace RE
{
	class BSWaterShaderMaterial;
	class NiTexture;

	class __declspec(novtable) TESWaterForm :
		public TESForm,     // 000
		public TESFullName  // 020
	{
	public:
		static constexpr auto RTTI{ RTTI::TESWaterForm };
		static constexpr auto VTABLE{ VTABLE::TESWaterForm };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kWATR };

		// members
		bool                    needUpdate;              // 030
		NiColorA                texScroll0;              // 034
		NiColorA                texScroll1;              // 044
		NiColorA                texScroll2;              // 054
		TESTexture              noiseTexture0;           // 068
		TESTexture              noiseTexture1;           // 078
		TESTexture              noiseTexture2;           // 088
		std::int8_t             alpha;                   // 098
		std::int8_t             flags;                   // 099
		BGSMaterialType*        materialType;            // 0A0
		BGSSoundDescriptorForm* waterSound;              // 0A8
		WaterShaderData         data;                    // 0B0
		TESWaterForm*           waterWeatherControl[3];  // 180
		std::int32_t            currentTextureSelect01;  // 198
		std::int32_t            currentTextureSelect02;  // 19C
		std::uint32_t           frequencyX;              // 1A0
		std::uint32_t           frequencyY;              // 1A4
		std::int32_t            octaves;                 // 1A8
		float                   amplitude;               // 1AC
		float                   lacunarity;              // 1B0
		float                   bias;                    // 1B4
		float                   gain;                    // 1B8
		SpellItem*              consumeSpell;            // 1C0
		SpellItem*              contactSpell;            // 1C8
		NiPointer<NiTexture>    niNoiseTexture0;         // 1D0
		NiPointer<NiTexture>    niNoiseTexture1;         // 1D8
		NiPointer<NiTexture>    niNoiseTexture2;         // 1E0
		TESObjectACTI*          placeableAutoWater;      // 1E8
		TESObjectACTI*          placeableLODWater;       // 1F0
		BSWaterShaderMaterial*  waterShaderMaterial;     // 1F8
		bool                    resetNoiseTextures;      // 200
		TESImageSpace*          imageSpace;              // 208
		NiPoint3                linearVelocity;          // 210
		NiPoint3                angularVelocity;         // 21C
	};
	static_assert(sizeof(TESWaterForm) == 0x228);
}
