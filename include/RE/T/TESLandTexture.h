#pragma once

namespace RE
{
	class __declspec(novtable) TESLandTexture :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESLandTexture };
		static constexpr auto VTABLE{ VTABLE::TESLandTexture };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kLTEX };

		// members
		BGSTextureSet* textureSet;          // 20
		TEXTURE_HAVOK_DATA      havokData;           // 28
		BGSMaterialType* materialType;        // 30
		std::int8_t             specularExponent;    // 38
		std::int32_t            shaderTextureIndex;  // 3C
		BSSimpleList<TESGrass*> textureGrassList;    // 40
	};
	static_assert(sizeof(TESLandTexture) == 0x50);
}
