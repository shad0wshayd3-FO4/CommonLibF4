#pragma once

#include "RE/N/NiPointer.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESTexture.h"
#include "RE/E/EffectShaderData.h"

namespace RE
{
	class BSGeometry;

	class __declspec(novtable) TESEffectShader :
		public TESForm,  // 000
		public TESModel  // 020
	{
	public:
		static constexpr auto RTTI{ RTTI::TESEffectShader };
		static constexpr auto VTABLE{ VTABLE::TESEffectShader };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kEFSH };

		// members
		EffectShaderData      data;                  // 050
		TESTexture            textureShaderTexture;  // 0F8
		TESTexture            blockOutTexture;       // 108
		TESTexture            paletteTexture;        // 118
		NiPointer<BSGeometry> shareableGeometry;     // 128
	};
	static_assert(sizeof(TESEffectShader) == 0x130);
}
