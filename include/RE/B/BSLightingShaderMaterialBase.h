#pragma once

#include "RE/B/BSShaderMaterial.h"
#include "RE/B/BSSpinLock.h"
#include "RE/N/NiColor.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class BSLightingShaderMaterialEnvmap;
	class BSShaderData;
	class BSTextureSet;
	class NiTexture;
	class NiStream;

	namespace BSGraphics
	{
		enum class TextureAddressMode;
	}

	class __declspec(novtable) BSLightingShaderMaterialBase :
		public BSShaderMaterial  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSLightingShaderMaterialBase };
		static constexpr auto VTABLE{ VTABLE::BSLightingShaderMaterialBase };

		// add
		virtual const BSLightingShaderMaterialEnvmap* IsLightingShaderMaterialEnvmap();                                          // 09
		virtual void                                  ClearTextures();                                                           // 0A
		virtual std::uint32_t                         GetTextures(NiTexture** a_textures, std::uint32_t a_arraySize);            // 0B
		virtual void                                  SaveBinary(NiStream* a_stream);                                            // 0C
		virtual void                                  LoadBinary(NiStream* a_stream);                                            // 0D
		virtual void                                  OnPrefetchTextures(void* a_outHandles, const BSTextureSet* a_textureSet);  // 0E - TextureDB::Handle
		virtual void                                  OnLoadTextureSet1(const BSTextureSet* a_textureSet, void* a_inHandles);    // 0F - TextureDB::Handle
		virtual void                                  OnLoadTextureSet2(const BSTextureSet* a_textureSet);                       // 10
		virtual void                                  DoReceiveValuesFromRootMaterial(const BSShaderData& a_rootData);           // 11

		void OnLoadTextureSet(const BSTextureSet* a_textureSet, void* a_inHandles)  // TextureDB::Handle
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
}
