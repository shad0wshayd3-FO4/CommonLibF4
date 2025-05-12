#pragma once

namespace RE
{
	class __declspec(novtable) ShaderReferenceEffect :
		public ReferenceEffect  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ShaderReferenceEffect };
		static constexpr auto VTABLE{ VTABLE::ShaderReferenceEffect };
		static constexpr auto Ni_RTTI{ Ni_RTTI::ShaderReferenceEffect };
		static constexpr auto TYPE{ TEMP_EFFECT_TYPE::kRefShader };

		~ShaderReferenceEffect() override;

		// members
		BSMagicShaderParticles                                     particles;               // 048
		BSTArray<BSTTuple<TextureDBHandle, NiPointer<NiTexture>*>> textureRequests;         // 068
		BSTArray<NiPointer<NiAVObject>>                            addOnObjects;            // 080
		BSTArray<BSModelDB::Handle>                                modelHandles;            // 098
		BSTArray<NiPointer<NiAVObject>>                            targetArray;             // 0B0
		BSSoundHandle                                              soundHandle;             // 0C8
		NiPointer<NiSourceTexture>                                 textureShaderTexture;    // 0D0
		NiPointer<NiSourceTexture>                                 textureBlockOutTexture;  // 0D8
		NiPointer<NiSourceTexture>                                 texturePaletteTexture;   // 0E0
		TESBoundObject*                                            wornObject;              // 0E8
		TESEffectShader*                                           effectData;              // 0F0
		BSEffectShaderData*                                        effectShaderData;        // 0F8
		NiPointer<NiAVObject>                                      lastRootNode;            // 100
		float                                                      alphaTimer;              // 104
		float                                                      addonAlpha;              // 108
		float                                                      addonScale;              // 10C
		float                                                      effectShaderAge;         // 110
		std::uint32_t                                              flags;                   // 114
		std::uint32_t                                              pushCount;               // 118
	};
	static_assert(sizeof(ShaderReferenceEffect) == 0x120);
}
