#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/UIShaderFXInfo.h"
#include "RE/NetImmerse/NiColor.h"
#include "RE/NetImmerse/NiPoint.h"
#include "RE/NetImmerse/NiSmartPointer.h"

namespace RE
{
	enum class UI_DEPTH_PRIORITY;

	class BSGeometry;
	class BSShaderAccumulator;
	class NiAVObject;
	class NiCamera;
	class NiDirectionalLight;
	class ShadowSceneNode;

	namespace Interface3D
	{
		enum class BackgroundMode
		{
			kLive,
			kStatic,
			kSolidColor
		};

		enum class PostEffect
		{
			kNone,
			kPipboy,
			kHUDGlass,
			kHUDGlassWithMod,
			kModMenu,
			kModMenuHighlightAll,
			kModMenuHighlightAllNoPulseOrScanLines
		};

		enum class HighlightEffect
		{
			kNone,
			kVATS
		};

		enum class OffscreenMenuSize
		{
			kPipboy,
			kFullFrame,
			kFullFrameText
		};

		enum class ScreenMode
		{
			kNone,
			kWorldAttached,
			kScreenAttached
		};

		enum class OffscreenMenuBlendMode
		{
			kAdditive,
			kAlpha
		};

		enum class LightType
		{
			kSpot,
			kShadowSpot,
			kPoint
		};

		class OldScreenEffectControl
		{
		public:
			// members
			NiPoint2 uvOffset;            // 00
			float    burstAmount;         // 08
			float    brightness;          // 0C
			float    vScanState;          // 10
			float    vScanRate;           // 14
			float    pulseIntensity;      // 18
			float    pulseRate;           // 1C
			float    flickerMinDelay;     // 20
			float    flickerMaxDelay;     // 24
			float    flickerMinDuration;  // 28
			float    flickerMaxDuration;  // 2C
			float    flickerFrequency;    // 30
			float    flickerBrightness;   // 34
			float    vScanDelayMin;       // 38
			float    vScanDelayMax;       // 3C
			bool     doScanlines;         // 40
			float    burstState;          // 44
			float    burstFadeRate;       // 48
			float    shudderState;        // 4C
			float    vScanDelay;          // 50
			float    flickerDelay;        // 54
			float    vHoldState;          // 58
			float    shudderScale;        // 5C
			float    shudderLength;       // 60
			float    vHoldRate;           // 64
			float    time;                // 68
			bool     flickering;          // 6C
		};
		static_assert(sizeof(OldScreenEffectControl) == 0x70);

		class Renderer
		{
		public:
			struct LightParams
			{
			public:
				// members
				REX::EnumSet<LightType, std::int32_t> type;          // 00
				float                                 spotFOV;       // 04
				NiPoint3                              lookAtPos;     // 08
				NiPointer<NiAVObject>                 lookAtObject;  // 18
				NiPointer<NiLight>                    light;         // 20
			};
			static_assert(sizeof(LightParams) == 0x28);

			static Renderer* Create(const BSFixedString& a_name, RE::UI_DEPTH_PRIORITY a_depth, float a_fov, bool a_alwaysRenderWhenEnabled)
			{
				using func_t = decltype(&Renderer::Create);
				static REL::Relocation<func_t> func{ REL::ID(88488) };
				return func(a_name, a_depth, a_fov, a_alwaysRenderWhenEnabled);
			}

			[[nodiscard]] static Renderer* GetByName(const BSFixedString& a_name)
			{
				using func_t = decltype(&Renderer::GetByName);
				static REL::Relocation<func_t> func{ REL::ID(140387) };
				return func(a_name);
			}

			void MainScreen_AddPointLight(
				NiPoint3 a_translation,
				NiColor  a_diffuse,
				float    a_radius,
				float    a_dimmerVal)
			{
				using func_t = decltype(&Renderer::MainScreen_AddPointLight);
				static REL::Relocation<func_t> func{ REL::ID(1335675) };
				return func(this, a_translation, a_diffuse, a_radius, a_dimmerVal);
			}

			void MainScreen_AddSpotLight(
				NiPoint3    a_translation,
				NiPoint3    a_lookAtPosition,
				NiAVObject* a_lookAtObject,
				float       a_fov,
				NiColor     a_diffuse,
				float       a_radius,
				float       a_dimmerVal,
				bool        a_castShadows)
			{
				using func_t = decltype(&Renderer::MainScreen_AddSpotLight);
				static REL::Relocation<func_t> func{ REL::ID(1056093) };
				return func(this, a_translation, a_lookAtPosition, a_lookAtObject, a_fov, a_diffuse, a_radius, a_dimmerVal, a_castShadows);
			}

			void MainScreen_ClearLights()
			{
				using func_t = decltype(&Renderer::MainScreen_ClearLights);
				static REL::Relocation<func_t> func{ REL::ID(683530) };
				return func(this);
			}

			void MainScreen_EnableAO(bool a_value)
			{
				enableAO = a_value;
			}

			void MainScreen_EnableScreenAttached3DMasking(
				const char* a_maskedGeomName,
				const char* a_maskedMaterialName)
			{
				maskedGeomName = a_maskedGeomName;
				maskedMaterialName = a_maskedMaterialName;
			}

			void MainScreen_RegisterGeometryRequiringFullViewport(NiAVObject* a_geometry)
			{
				elementRequiringFullVieport = a_geometry;
			}

			void MainScreen_SetBackgroundMode(BackgroundMode a_mode)
			{
				bgmode = a_mode;
			}

			void MainScreen_SetClearDepthStencil(bool a_clear)
			{
				clearDepthStencilMainScreen = a_clear;
			}

			void MainScreen_SetMenuBlendMode(OffscreenMenuBlendMode a_mode)
			{
				menuBlend = a_mode;
			}

			void MainScreen_SetMenuIntensity(float a_diffuse, float a_emit)
			{
				menuDiffuseIntensity = a_diffuse;
				menuEmitIntensity = a_emit;
			}

			void MainScreen_SetOpacityAlpha(float a_opacityAlpha)
			{
				opacityAlpha = a_opacityAlpha;
			}

			void MainScreen_SetPostAA(bool a_value)
			{
				postAA = a_value;
			}

			void MainScreen_SetScreenAttached3D(NiAVObject* a_root3D)
			{
				using func_t = decltype(&Renderer::MainScreen_SetScreenAttached3D);
				static REL::Relocation<func_t> func{ REL::ID(817727) };
				return func(this, a_root3D);
			}

			void MainScreen_SetUseDeferredRenderer(bool a_value)
			{
				defRenderMainScreen = a_value;
			}

			void MainScreen_SetWorldAttached3D(NiAVObject* a_root3D)
			{
				using func_t = decltype(&Renderer::MainScreen_SetWorldAttached3D);
				static REL::Relocation<func_t> func{ REL::ID(724778) };
				return func(this, a_root3D);
			}

			void MainScreen_SetWorldAttachedMenuIntensity(float a_diffuse, float a_emit)
			{
				menuDiffuseIntensityWA = a_diffuse;
				menuEmitIntensityWA = a_emit;
			}

			void MainScreen_SetHideScreenWhenDisabled(bool a_value)
			{
				hideScreenWhenDisabled = a_value;
			}

			void Offscreen_AddLight(
				NiPoint3 a_translation,
				NiColor  a_diffuse,
				NiColor  a_specular,
				float    a_dimmerVal)
			{
				using func_t = decltype(&Renderer::Offscreen_AddLight);
				static REL::Relocation<func_t> func{ REL::ID(1267198) };
				return func(this, a_translation, a_diffuse, a_specular, a_dimmerVal);
			}

			void Offscreen_Clear3D()
			{
				using func_t = decltype(&Renderer::Offscreen_Clear3D);
				static REL::Relocation<func_t> func{ REL::ID(1533262) };
				return func(this);
			}

			void Offscreen_ClearLights()
			{
				using func_t = decltype(&Renderer::Offscreen_ClearLights);
				static REL::Relocation<func_t> func{ REL::ID(1039253) };
				return func(this);
			}

			void Offscreen_Enable3D(bool a_value)
			{
				offscreen3DEnabled = a_value;
			}

			std::uint32_t Offscreen_GetRenderTargetHeight()
			{
				using func_t = decltype(&Renderer::Offscreen_GetRenderTargetHeight);
				static REL::Relocation<func_t> func{ REL::ID(1280897) };
				return func(this);
			}

			std::uint32_t Offscreen_GetRenderTargetWidth()
			{
				using func_t = decltype(&Renderer::Offscreen_GetRenderTargetWidth);
				static REL::Relocation<func_t> func{ REL::ID(403273) };
				return func(this);
			}

			void Offscreen_Set3D(NiAVObject* a_3D)
			{
				using func_t = decltype(&Renderer::Offscreen_Set3D);
				static REL::Relocation<func_t> func{ REL::ID(43983) };
				return func(this, a_3D);
			}

			void Offscreen_SetBackgroundColor(const NiColorA& a_color)
			{
				clearColor = a_color;
			}

			void Offscreen_SetClearDepthStencil(bool a_clear)
			{
				clearDepthStencilOffscreen = a_clear;
			}

			void Offscreen_SetClearRenderTarget(bool a_clear)
			{
				clearRenderTarget = a_clear;
			}

			void Offscreen_SetDebugMode(bool a_on, bool a_small, std::uint32_t a_target)
			{
				using func_t = decltype(&Renderer::Offscreen_SetDebugMode);
				static REL::Relocation<func_t> func{ REL::ID(1277879) };
				return func(this, a_on, a_small, a_target);
			}

			void Offscreen_SetDirectionalLight(
				float   a_xyPlaneAngle,
				float   a_zAngle,
				NiColor a_diffuse,
				float   a_dimmerVal)
			{
				using func_t = decltype(&Renderer::Offscreen_SetDirectionalLight);
				static REL::Relocation<func_t> func{ REL::ID(987144) };
				return func(this, a_xyPlaneAngle, a_zAngle, a_diffuse, a_dimmerVal);
			}

			void Offscreen_SetDisplayMode(
				ScreenMode  a_mode,
				const char* a_screenGeomName,
				const char* a_screenMaterialName)
			{
				screenmode = a_mode;
				screenGeomName = a_screenGeomName;
				screenMaterialName = a_screenMaterialName;
			}

			void Offscreen_SetPostEffect(PostEffect a_effect)
			{
				postfx = a_effect;
			}

			void Offscreen_SetRenderTargetSize(OffscreenMenuSize a_size)
			{
				omsize = a_size;
			}

			void Offscreen_SetUseLongRangeCamera(bool a_use)
			{
				useLongRangeCamera = a_use;
			}

			void Enable(bool a_unhideGeometries = false)
			{
				using func_t = decltype(&Renderer::Enable);
				static REL::Relocation<func_t> func{ REL::ID(326895) };
				return func(this, a_unhideGeometries);
			}

			void Disable()
			{
				using func_t = decltype(&Renderer::Disable);
				static REL::Relocation<func_t> func{ REL::ID(938370) };
				return func(this);
			}

			static void DisableAll(bool a_disableAll)
			{
				using func_t = decltype(&Renderer::DisableAll);
				static REL::Relocation<func_t> func{ REL::ID(2222521) };
				return func(a_disableAll);
			}

			void Release()
			{
				using func_t = decltype(&Renderer::Release);
				static REL::Relocation<func_t> func{ REL::ID(74749) };
				return func(this);
			}

			void SetViewport(RE::Scaleform::GFx::Movie& a_ui, const NiRect<float>& a_renderArea)
			{
				using func_t = decltype(&Renderer::SetViewport);
				static REL::Relocation<func_t> func{ REL::ID(825410) };
				return func(this, a_ui, a_renderArea);
			}

			// members
			BSTAlignedArray<UIShaderFXInfo>                    colorFXInfos;                 // 000
			BSTAlignedArray<UIShaderFXInfo>                    backgroundFXInfos;            // 018
			BSReadWriteLock                                    cachedQuadsLock;              // 030
			NiColorA                                           clearColor;                   // 038
			float                                              opacityAlpha;                 // 048
			bool                                               enabled;                      // 04C
			bool                                               offscreen3DEnabled;           // 04D
			bool                                               hideScreenWhenDisabled;       // 04E
			bool                                               usePremultAlpha;              // 04F
			bool                                               clearRenderTarget;            // 050
			bool                                               clearDepthStencilMainScreen;  // 051
			bool                                               clearDepthStencilOffscreen;   // 052
			bool                                               postAA;                       // 053
			bool                                               useFullPremultAlpha;          // 054
			bool                                               alwaysRenderWhenEnabled;      // 055
			bool                                               defRenderMainScreen;          // 056
			bool                                               enableAO;                     // 057
			bool                                               useLongRangeCamera;           // 058
			bool                                               needsLightSetup;              // 059
			bool                                               needsLightSetupOffscreen;     // 05A
			REX::EnumSet<BackgroundMode, std::int32_t>         bgmode;                       // 05C
			REX::EnumSet<PostEffect, std::int32_t>             postfx;                       // 060
			REX::EnumSet<HighlightEffect, std::int32_t>        highlightfx;                  // 064
			REX::EnumSet<OffscreenMenuSize, std::int32_t>      omsize;                       // 068
			REX::EnumSet<ScreenMode, std::int32_t>             screenmode;                   // 06C
			REX::EnumSet<OffscreenMenuBlendMode, std::int32_t> menuBlend;                    // 070
			REX::EnumSet<UI_DEPTH_PRIORITY, std::int32_t>      depth;                        // 074
			NiPointer<NiAVObject>                              worldAttachedElementRoot;     // 078
			NiPointer<NiAVObject>                              screenAttachedElementRoot;    // 080
			NiPointer<NiAVObject>                              offscreenElement;             // 088
			BSTArray<NiPointer<BSGeometry>>                    displayGeometry;              // 090
			NiAVObject*                                        elementRequiringFullVieport;  // 0A8
			NiAVObject*                                        highlightedElement;           // 0B0
			bool                                               highlightOffscreen;           // 0B8
			OldScreenEffectControl                             pipfx;                        // 0BC
			OldScreenEffectControl                             vatsfx;                       // 12C
			NiPointer<BSShaderAccumulator>                     accum;                        // 1A0
			NiPointer<NiCamera>                                pipboyAspect;                 // 1A8
			NiPointer<NiCamera>                                nativeAspect;                 // 1B0
			NiPointer<NiCamera>                                nativeAspectLongRange;        // 1B8
			std::int32_t                                       customRenderTarget;           // 1C0
			std::int32_t                                       customSwapTarget;             // 1C4
			BSTArray<LightParams>                              mainLights;                   // 1C8
			BSTArray<LightParams>                              offscreenLights;              // 1E0
			float                                              menuDiffuseIntensity;         // 1F8
			float                                              menuEmitIntensity;            // 1FC
			float                                              menuDiffuseIntensityWA;       // 200
			float                                              menuEmitIntensityWA;          // 204
			BSFixedString                                      name;                         // 208
			BSFixedString                                      screenGeomName;               // 210
			BSFixedString                                      screenMaterialName;           // 218
			BSFixedString                                      maskedGeomName;               // 220
			BSFixedString                                      maskedMaterialName;           // 228
			NiDirectionalLight*                                directionalLight;             // 230
			NiPointer<ShadowSceneNode>                         screenSSN;                    // 238
			NiPointer<ShadowSceneNode>                         offscreenSSN;                 // 240
		};
		static_assert(sizeof(Renderer) == 0x248);
	}
}
