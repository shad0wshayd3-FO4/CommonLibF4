#pragma once

#include "RE/Bethesda/BSModelDB.h"
#include "RE/Bethesda/BSPointerHandle.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTList.h"
#include "RE/Bethesda/BSTSmartPointer.h"
#include "RE/Bethesda/BSTTuple.h"
#include "RE/Bethesda/ReferenceEffectController.h"
#include "RE/NetImmerse/NiColor.h"
#include "RE/NetImmerse/NiSmartPointer.h"

namespace RE
{
	class Atmosphere;
	class BGSLightingTemplate;
	class BSMultiBoundNode;
	class Clouds;
	class ImageSpaceModifierInstanceForm;
	class Moon;
	class NiNode;
	class NiTexture;
	class Precipitation;
	class ReferenceEffect;
	class SkySound;
	class Stars;
	class Sun;
	class TESClimate;
	class TESImageSpace;
	class TESRegion;
	class TESWeather;

	class __declspec(novtable) Sky
	{
	public:
		static constexpr auto RTTI{ RTTI::Sky };
		static constexpr auto VTABLE{ VTABLE::Sky };

		enum class Mode
		{
			kNone = 0,
			kInterior,
			kSkyDomeOnly,
			kFull,

			kTotal
		};

		enum class Flags
		{
			kNone = 0,
			kFastTravel = 1 << 4,
			kHideSky = 1 << 7,
			kUpdateSunriseBegin = 1 << 9,
			kUpdateSunriseEnd = 1 << 10,
			kUpdateSunsetBegin = 1 << 11,
			kUpdateSunsetEnd = 1 << 12,
			kUpdateColorsSunriseBegin = 1 << 13,
			kUpdateColorsSunsetEnd = 1 << 14,
			kUpdateWind = 1 << 20,
			kReleaseWeatherOverride = 1 << 21
		};

		struct SkyStaticRefData
		{
		public:
			// members
			BSTTuple<ObjectRefHandle, std::uint8_t> data;  // 00
		};
		static_assert(sizeof(SkyStaticRefData) == 0x8);

		virtual ~Sky();  // 00

		[[nodiscard]] static Sky* GetSingleton()
		{
			using func_t = decltype(&Sky::GetSingleton);
			static REL::Relocation<func_t> func{ REL::ID(2192448) };
			return func();
		}

		void ForceWeather(TESWeather* a_weather, bool a_override)
		{
			using func_t = decltype(&Sky::ForceWeather);
			static REL::Relocation<func_t> func{ REL::ID(2208861) };
			return func(this, a_weather, a_override);
		}

		void ReleaseWeatherOverride()
		{
			if (overrideWeather) {
				flags.set(Flags::kReleaseWeatherOverride);
				overrideWeather = nullptr;
			}
		}

		void ResetWeather()
		{
			using func_t = decltype(&Sky::ResetWeather);
			static REL::Relocation<func_t> func{ REL::ID(2208860) };
			return func(this);
		}

		// members
		NiPointer<BSMultiBoundNode>        root;                             // 008
		NiPointer<NiNode>                  moonsRoot;                        // 010
		NiPointer<NiNode>                  auroraRoot;                       // 018
		ModelDBHandle                      aurora3d;                         // 020
		BGSLightingTemplate*               extLightingOverride;              // 028
		ObjectRefHandle                    currentRoom;                      // 030
		ObjectRefHandle                    previousRoom;                     // 034
		float                              lightingTransition;               // 038
		float                              lightingTransitionTimer;          // 03C
		TESClimate*                        currentClimate;                   // 040
		TESWeather*                        currentWeather;                   // 048
		TESWeather*                        lastWeather;                      // 050
		TESWeather*                        defaultWeather;                   // 058
		TESWeather*                        overrideWeather;                  // 060
		TESRegion*                         currentRegion;                    // 068
		Atmosphere*                        atmosphere;                       // 070
		Stars*                             stars;                            // 078
		Sun*                               sun;                              // 080
		Clouds*                            clouds;                           // 088
		Moon*                              masser;                           // 090
		Moon*                              secunda;                          // 098
		Precipitation*                     precip;                           // 0A0
		NiColor                            skyColor[19];                     // 0A8
		NiColor                            prevSkyColorA[19];                // 18C
		NiColor                            prevDirAmbColorsA[3][2];          // 270
		NiColorA                           prevSpecTintFres;                 // 2B8
		TESImageSpace*                     prevImageSpace;                   // 2C8
		float                              prevFogDistancesA[8];             // 2D0
		float                              prevFogHeight;                    // 2F0
		float                              prevFogPower;                     // 2F4
		float                              prevFogClamp;                     // 2F8
		float                              prevFogHighDensityScale;          // 2FC
		float                              lastExtWetness;                   // 300
		NiColor                            waterFogColor;                    // 304
		NiColor                            sunSpecularColor;                 // 310
		float                              windSpeed;                        // 31C
		float                              windAngle;                        // 320
		float                              windTurbulence;                   // 324
		float                              fogDistances[8];                  // 328
		float                              fogHeight;                        // 348
		float                              fogPower;                         // 34C
		float                              fogClamp;                         // 350
		float                              fogHighDensityScale;              // 354
		float                              currentGameHour;                  // 358
		float                              lastWeatherUpdate;                // 35C
		float                              currentWeatherPct;                // 360
		float                              lastWindDirection;                // 364
		float                              lastWindDirectionRange;           // 368
		REX::EnumSet<Mode, std::uint32_t>  mode;                             // 36C
		BSSimpleList<SkySound*>*           skySoundList;                     // 370
		float                              flash;                            // 378
		std::uint64_t                      flashTime;                        // 380
		std::uint32_t                      lastMoonPhaseUpdate;              // 388
		float                              windowReflectionTimer;            // 38C
		float                              accelBeginPct;                    // 390
		REX::EnumSet<Flags, std::uint32_t> flags;                            // 394
		ImageSpaceModifierInstanceForm*    currentWeatherImageSpaceMod;      // 398
		ImageSpaceModifierInstanceForm*    currentWeatherImageSpaceMod2;     // 3A0
		ImageSpaceModifierInstanceForm*    lastWeatherImageSpaceMod;         // 3A8
		ImageSpaceModifierInstanceForm*    lastWeatherImageSpaceMod2;        // 3B0
		NiColor                            directionalAmbientColorsA[3][2];  // 3B8
		NiColor                            ambientSpecularTint;              // 400
		float                              ambientSpecularFresnel;           // 40C
		float                              auroraInStart;                    // 410
		float                              auroraIn;                         // 414
		float                              auroraOutStart;                   // 418
		float                              auroraOut;                        // 41C
		NiPointer<ReferenceEffect>         currentReferenceEffect;           // 420
		NiPointer<ReferenceEffect>         lastReferenceEffect;              // 428
		SkyEffectController                effectController;                 // 430
		BSTArray<NiPointer<NiTexture>>     storedCloudTextures;              // 438
		BSTArray<NiPointer<NiTexture>>     storedWorldMapCloudTextures;      // 450
		BSTArray<Sky::SkyStaticRefData>    skyStaticRefData;                 // 468
	};
	static_assert(sizeof(Sky) == 0x480);
}
