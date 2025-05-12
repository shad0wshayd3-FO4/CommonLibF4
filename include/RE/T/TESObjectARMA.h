#pragma once

#include "RE/T/TESObject.h"
#include "RE/T/TESRaceForm.h"
#include "RE/B/BGSBipedObjectForm.h"

namespace RE
{
	class __declspec(novtable) TESObjectARMA :
		public TESObject,          // 000
		public TESRaceForm,        // 020
		public BGSBipedObjectForm  // 030
	{
	public:
		static constexpr auto RTTI{ RTTI::TESObjectARMA };
		static constexpr auto VTABLE{ VTABLE::TESObjectARMA };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kARMA };

		// members
		OBJ_ARMA                             data;                     // 040
		BGSModelMaterialSwap                 bipedModel[2];            // 050
		BGSModelMaterialSwap                 bipedModelFacebones[2];   // 0D0
		BGSModelMaterialSwap                 bipedModel1stPerson[2];   // 150
		BGSTextureSet*                       skinTextures[2];          // 1D0
		BGSListForm*                         skinTextureSwapLists[2];  // 1E0
		BSTArray<TESRace*>                   additionalRaces;          // 1F0
		BGSFootstepSet*                      footstepSet;              // 208
		BGSArtObject*                        artObject;                // 210
		BSTHashMap<BSFixedString, NiPoint3>* scaleModifiers[2];        // 218
	};
	static_assert(sizeof(TESObjectARMA) == 0x228);
}
