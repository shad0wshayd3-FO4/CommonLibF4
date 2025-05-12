#pragma once

namespace RE
{
	class BGSBodyPart
	{
	public:
		// members
		BSFixedString                    nodeName;                      // 000
		BSFixedString                    targetName;                    // 008
		BSFixedString                    hitReactionVariablePrefix;     // 010
		BGSBodyPartDefs::HitReactionData runtimeHitReactionData;        // 018
		BGSLocalizedString               partName;                      // 040
		BSFixedString                    goreObjectName;                // 048
		TESModel                         explosionSpecialDebris;        // 050
		PART_DATA                        data;                          // 080
		BGSArtObject*                    dismemberBlood;                // 128
		BGSMaterialType*                 bloodImpactMaterial;           // 130
		BGSMaterialType*                 onCrippleBloodImpactMaterial;  // 138
		BGSTextureSet*                   meatCapTextureSet;             // 140
		BGSTextureSet*                   meatCollarTextureSet;          // 148
	};
	static_assert(sizeof(BGSBodyPart) == 0x150);
}
