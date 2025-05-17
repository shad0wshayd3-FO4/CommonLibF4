#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSResource_ID.h"
#include "RE/B/BSShaderData.h"
#include "RE/B/BSTextureSet.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESTexture.h"

namespace RE
{
	class DecalData;

	class __declspec(novtable) BGSTextureSet :
		public TESBoundObject,  // 000
		public BSTextureSet     // 068
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSTextureSet };
		static constexpr auto VTABLE{ VTABLE::BGSTextureSet };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kTXST };

		F4_HEAP_REDEFINE_NEW(BGSTextureSet);

		// members
		BSFixedString  materialName;       // 078
		TESTexture     textures[8];        // 080
		DecalData*     decalData;          // 100
		std::uint16_t  flags;              // 108
		BSResource::ID textureFileIDs[8];  // 10C
		BSShaderData   materialData;       // 170
	};
	static_assert(sizeof(BGSTextureSet) == 0x350);
}
