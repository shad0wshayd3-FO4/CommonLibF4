#pragma once

#include "RE/Bethesda/BSGraphics.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSTSmartPointer.h"
#include "RE/Bethesda/BSTextureDB.h"
#include "RE/NetImmerse/NiColor.h"
#include "RE/NetImmerse/NiPoint.h"
#include "RE/NetImmerse/NiSmartPointer.h"

namespace RE
{
	class BSLightingShaderMaterialEnvmap;
	class BSTextureSet;
	class NiTexture;

	class __declspec(novtable) BSShaderMaterial :
		public BSIntrusiveRefCounted  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSShaderMaterial };
		static constexpr auto VTABLE{ VTABLE::BSShaderMaterial };

		enum class Feature
		{
			kNone = static_cast<std::underlying_type_t<Feature>>(-1),
			kDefault = 0x0,
			kEnvmap = 0x1,
			kGlowmap = 0x2,
			kParallax = 0x3,
			kFace = 0x4,
			kSkinTint = 0x5,
			kHairTint = 0x6,
			kParallaxOcc = 0x7,
			kLandscape = 0x8,
			kLODLandscape = 0x9,
			kSnow = 0xA,
			kMultiLayerParallax = 0xB,
			kTreeAnim = 0xC,
			kLODObjects = 0xD,
			kMultiIndexSnow = 0xE,
			kLODObjectsHD = 0xF,
			kEye = 0x10,
			kCloud = 0x11,
			kLODLandscapeNoise = 0x12,
			kLODLandscapeBlend = 0x13,
			kDismemberment = 0x14
		};

		enum class Type
		{
			kBase = 0x0,
			kEffect = 0x1,
			kLighting = 0x2,
			kWater = 0x3
		};

		virtual ~BSShaderMaterial();

		// add
		virtual BSShaderMaterial* Create();                                                     // 01
		virtual void              CopyMembers(const BSShaderMaterial* a_other);                 // 02
		virtual std::uint32_t     ComputeCRC32(std::uint32_t a_uniqueID, bool a_combining);     // 03
		virtual BSShaderMaterial* GetDefault();                                                 // 04
		virtual Feature           GetFeature();                                                 // 05
		virtual Type              GetType();                                                    // 06
		virtual void              ReceiveValuesFromRootMaterial(BSShaderProperty* a_property);  // 07
		virtual bool              DoIsCopy(const BSShaderMaterial* a_other);                    // 08

		// members
		NiPoint2      texCoordOffset[2];  // 0C
		NiPoint2      texCoordScale[2];   // 1C
		std::uint32_t hashKey;            // 2C
		std::uint32_t uniqueCode;         // 30
	};
	static_assert(sizeof(BSShaderMaterial) == 0x38);

	struct __declspec(novtable) BSLightingShaderMaterialBase :
		public BSShaderMaterial  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSLightingShaderMaterialBase };
		static constexpr auto VTABLE{ VTABLE::BSLightingShaderMaterialBase };

		// add
		virtual const BSLightingShaderMaterialEnvmap* IsLightingShaderMaterialEnvmap();                                                     // 09
		virtual void                                  ClearTextures();                                                                      // 0A
		virtual std::uint32_t                         GetTextures(NiTexture** a_textures, std::uint32_t a_arraySize);                       // 0B
		virtual void                                  SaveBinary(NiStream* a_stream);                                                       // 0C
		virtual void                                  LoadBinary(NiStream* a_stream);                                                       // 0D
		virtual void                                  OnPrefetchTextures(TextureDBHandle* a_outHandles, const BSTextureSet* a_textureSet);  // 0E
		virtual void                                  OnLoadTextureSet1(const BSTextureSet* a_textureSet, TextureDBHandle* a_inHandles);    // 0F
		virtual void                                  OnLoadTextureSet2(const BSTextureSet* a_textureSet);                                  // 10
		virtual void                                  DoReceiveValuesFromRootMaterial(const BSShaderData& a_rootData);                      // 11

		void OnLoadTextureSet(const BSTextureSet* a_textureSet, TextureDBHandle* a_inHandles)
		{
			return OnLoadTextureSet1(a_textureSet, a_inHandles);
		}

		void OnLoadTextureSet(const BSTextureSet* a_textureSet)
		{
			return OnLoadTextureSet2(a_textureSet);
		}

		// members
		NiColor                        specularColor;                  // 38
		NiPointer<NiTexture>           diffuseTexture;                 // 40
		NiPointer<NiTexture>           normalTexture;                  // 48
		NiPointer<NiTexture>           rimSoftLightingTexture;         // 50
		NiPointer<NiTexture>           smoothnessSpecMaskTexture;      // 58
		NiPointer<NiTexture>           lookupTexture;                  // 60
		BSGraphics::TextureAddressMode textureClampMode;               // 68
		NiPointer<BSTextureSet>        textureSet;                     // 70
		float                          materialAlpha;                  // 74
		float                          refractionPower;                // 78
		float                          smoothness;                     // 7C
		float                          specularColorScale;             // 80
		float                          fresnelPower;                   // 84
		float                          wetnessControl_SpecScale;       // 88
		float                          wetnessControl_SpecPowerScale;  // 8C
		float                          wetnessControl_SpecMin;         // 90
		float                          wetnessControl_EnvMapScale;     // 94
		float                          wetnessControl_FresnelPower;    // 98
		float                          wetnessControl_Metalness;       // 9C
		float                          subSurfaceLightRolloff;         // A0
		float                          rimLightPower;                  // A4
		float                          backLightPower;                 // A8
		float                          lookupScale;                    // AC
		BSNonReentrantSpinLock         loadTextureSetLock;             // B0
	};
	static_assert(sizeof(BSLightingShaderMaterialBase) == 0xC0);

	struct __declspec(novtable) BSLightingShaderMaterial :
		public BSLightingShaderMaterialBase  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSLightingShaderMaterial };
		static constexpr auto VTABLE{ VTABLE::BSLightingShaderMaterial };
	};
	static_assert(sizeof(BSLightingShaderMaterial) == 0xC0);
}
