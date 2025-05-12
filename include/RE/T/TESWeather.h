#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) TESWeather :
		public TESForm  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::TESWeather };
		static constexpr auto VTABLE{ VTABLE::TESWeather };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kWTHR };

		enum class SpellContext
		{
			kApplyOnLightning = 0x0,
			kApplyWhenActive = 0x1
		};

		enum class SoundType
		{
			kDefault = 0x0,
			kPrecipitation = 0x1,
			kWind = 0x2,
			kThunder = 0x3
		};

		struct SpellData
		{
		public:
			// members
			MagicItem* spell;      // 00
			float      threshold;  // 08
		};
		static_assert(sizeof(SpellData) == 0x10);

		struct WeatherSound
		{
		public:
			// members
			BGSSoundDescriptorForm*               soundForm;  // 00
			REX::EnumSet<SoundType, std::int32_t> type;       // 08
		};
		static_assert(sizeof(WeatherSound) == 0x10);

		struct WeatherSoundList :
			public BSSimpleList<WeatherSound*>
		{
		public:
		};
		static_assert(sizeof(WeatherSoundList) == 0x10);

		// members
		REX::EnumSet<SpellContext, std::int32_t> context;                              // 020
		TESTexture1024                           cloudTexture[32];                     // 028
		std::int8_t                              cloudLayerSpeedY[32];                 // 228
		std::int8_t                              cloudLayerSpeedX[32];                 // 248
		std::uint32_t                            cloudColorData[32][8];                // 268
		float                                    cloudAlpha[32][8];                    // 668
		std::uint32_t                            cloudLayerDisabledBits;               // A68
		std::int8_t                              weatherData[20];                      // A6C
		float                                    fogData[18];                          // A80
		std::uint32_t                            colorData[19][8];                     // AC8
		float                                    fogColorScales[4][8];                 // D28
		SpellData                                weatherSpellData[2];                  // DA8
		WeatherSoundList                         soundList;                            // DC8
		BSTArray<TESObjectSTAT*>                 skyStatics;                           // DD8
		std::uint32_t                            numCloudLayers;                       // DF0
		TESImageSpace*                           imageSpace[8];                        // DF8
		BGSGodRays*                              godRays[8];                           // E38
		BGSDirectionalAmbientLightingColors      directionalAmbientLightingColors[8];  // E78
		TESModel                                 aurora;                               // F78
		BGSLensFlare*                            sunGlareLensFlare;                    // FA8
		float                                    volatilityMult;                       // FB0
		float                                    visibilityMult;                       // FB4
		BGSShaderParticleGeometryData*           precipitationData;                    // FB8
		BGSReferenceEffect*                      referenceEffect;                      // FC0
	};
	static_assert(sizeof(TESWeather) == 0xFC8);
}
