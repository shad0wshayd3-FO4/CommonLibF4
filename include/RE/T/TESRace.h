#pragma once

#include "RE/B/BGSAttackDataForm.h"
#include "RE/B/BGSBipedObjectForm.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSPreloadable.h"
#include "RE/B/BGSPropertySheet.h"
#include "RE/B/BGSSkinForm.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESSpellList.h"

namespace RE
{
	class __declspec(novtable) TESRace :
		public TESForm,             // 000
		public TESFullName,         // 020
		public TESDescription,      // 030
		public TESSpellList,        // 048
		public BGSSkinForm,         // 058
		public BGSBipedObjectForm,  // 068
		public BGSKeywordForm,      // 078
		public BGSAttackDataForm,   // 098
		public BGSPropertySheet,    // 0A8
		public BGSPreloadable       // 0B8
	{
	public:
		static constexpr auto RTTI{ RTTI::TESRace };
		static constexpr auto VTABLE{ VTABLE::TESRace };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kRACE };

		struct MOVEMENT_SPEED_OVERRIDE
		{
		public:
			// members
			BGSMovementType*    moveType;      // 00
			Movement::MaxSpeeds overrideData;  // 08
		};
		static_assert(sizeof(MOVEMENT_SPEED_OVERRIDE) == 0x78);

		struct FaceRelatedData
		{
		public:
			// members
			BGSCharacterTint::Template::Groups*             tintingTemplate;               //
			BSTArray<BGSTextureSet*>*                       faceDetailsTextureSets;        //
			BGSTextureSet*                                  defaultFaceDetailsTextureSet;  //
			BSTArray<TESNPC*>*                              presetNPCs;                    //
			BSTArray<BGSColorForm*>*                        availableHairColors;           //
			BGSColorForm*                                   defaultHairColor;              //
			BSTArray<BGSHeadPart*>*                         headParts;                     //
			BSTArray<BGSCharacterMorph::Group*>*            morphGroups;                   //
			BSTArray<BGSCharacterMorph::FacialBoneRegion*>* facialBoneRegions;             //
			BGSCharacterMorph::FacialBoneRegion*            neckFatFacialBoneRegion;       //
			NiPoint3                                        neckFatAdjustmentScales;       //
			BSFixedString                                   wrinkleMapPath;                //
		};
		static_assert(sizeof(FaceRelatedData) == 0x68);

		struct BodyMorphData
		{
		public:
			// members
			BSTHashMap<BSFixedString, BGSCharacterMorph::BoneBaseScales*>        boneBaseScales;  // 00
			BSTHashMap<BSFixedString, BGSCharacterMorph::BONE_MODIFIER_MIN_MAX*> boneModifiers;   // 30
		};
		static_assert(sizeof(BodyMorphData) == 0x60);

		// members
		TESModel                                              skeletonModel[2];             // 0C0
		TESModel                                              skeletonChargenModel[2];      // 120
		RACE_DATA                                             data;                         // 180
		float                                                 clampFaceGeoValue;            // 280
		float                                                 clampFaceGeoValue2;           // 284
		BGSTextureModel                                       bodyTextureModels[2];         // 288
		BGSBehaviorGraphModel                                 behaviorGraph[2];             // 2E8
		BSFixedString                                         rootBehaviorGraphName[2];     // 348
		BSFixedString                                         behaviorGraphProjectName[2];  // 358
		BGSVoiceType*                                         defaultVoiceType[2];          // 368
		BGSBodyPartData*                                      bodyPartData;                 // 378
		BGSSoundTagComponent                                  soundTagComponent;            // 380
		BGSAttachParentArray                                  attachParents;                // 388
		BSFixedString                                         formEditorID;                 // 3A0
		BGSMaterialType*                                      bloodImpactMaterial;          // 3A8
		BGSArtObject*                                         dismemberBlood;               // 3B0
		BGSTextureSet*                                        meatCapTextureSet;            // 3B8
		BGSTextureSet*                                        meatCollarTextureSet;         // 3C0
		BGSSoundDescriptorForm*                               corpseOpenSound;              // 3C8
		BGSSoundDescriptorForm*                               corpseCloseSound;             // 3D0
		BSFixedString                                         bipedObjectNames[32];         // 3D8
		ActorValueInfo*                                       bipedObjectConditions[32];    // 4D8
		BSTArray<EquipSlotData>                               equipSlotArray;               // 5D8
		std::uint32_t                                         validEquipTypes;              // 5F0
		TESObjectWEAP*                                        unarmedWeapon;                // 5F8
		TESRace*                                              morphRace;                    // 600
		TESRace*                                              armorParentRace;              // 608
		TESQuest*                                             dialogueQuest;                // 610
		BSTArray<MOVEMENT_SPEED_OVERRIDE>                     speedOverrides;               // 618
		BSTArray<BSFixedString>                               phonemeTargets;               // 630
		BSTHashMap<std::uint32_t, BGSCharacterMorph::Slider*> morphSliders;                 // 648
		BGSMovementType*                                      baseMoveTypes[4];             // 678
		FaceRelatedData*                                      faceRelatedData[2];           // 698
		TESRace::BodyMorphData*                               bodyMorphData[2];             // 6A8
		TESTexture                                            hairColorLookupTexture;       // 6B8
		TESTexture                                            hairColorLookupTextureExt;    // 6C8
	};
	static_assert(sizeof(TESRace) == 0x6D8);
}
