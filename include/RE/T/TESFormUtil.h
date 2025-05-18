#pragma once

#include "RE/A/Actor.h"
#include "RE/A/ActorValueInfo.h"
#include "RE/A/AlchemyItem.h"
#include "RE/A/ArrowProjectile.h"
#include "RE/B/BGSAcousticSpace.h"
#include "RE/B/BGSAction.h"
#include "RE/B/BGSAddonNode.h"
#include "RE/B/BGSAimModel.h"
#include "RE/B/BGSArtObject.h"
#include "RE/B/BGSAssociationType.h"
#include "RE/B/BGSAttractionRule.h"
#include "RE/B/BGSAudioEffectChain.h"
#include "RE/B/BGSBendableSpline.h"
#include "RE/B/BGSBodyPartData.h"
#include "RE/B/BGSCameraPath.h"
#include "RE/B/BGSCameraShot.h"
#include "RE/B/BGSCollisionLayer.h"
#include "RE/B/BGSColorForm.h"
#include "RE/B/BGSComponent.h"
#include "RE/B/BGSConstructibleObject.h"
#include "RE/B/BGSDamageType.h"
#include "RE/B/BGSDebris.h"
#include "RE/B/BGSDefaultObject.h"
#include "RE/B/BGSDefaultObjectManager.h"
#include "RE/B/BGSDialogueBranch.h"
#include "RE/B/BGSDualCastData.h"
#include "RE/B/BGSEncounterZone.h"
#include "RE/B/BGSEquipSlot.h"
#include "RE/B/BGSExplosion.h"
#include "RE/B/BGSFootstep.h"
#include "RE/B/BGSFootstepSet.h"
#include "RE/B/BGSGodRays.h"
#include "RE/B/BGSHazard.h"
#include "RE/B/BGSHeadPart.h"
#include "RE/B/BGSIdleMarker.h"
#include "RE/B/BGSImpactData.h"
#include "RE/B/BGSImpactDataSet.h"
#include "RE/B/BGSInstanceNamingRules.h"
#include "RE/B/BGSKeyword.h"
#include "RE/B/BGSLensFlare.h"
#include "RE/B/BGSLightingTemplate.h"
#include "RE/B/BGSListForm.h"
#include "RE/B/BGSLocation.h"
#include "RE/B/BGSLocationRefType.h"
#include "RE/B/BGSMaterialObject.h"
#include "RE/B/BGSMaterialSwap.h"
#include "RE/B/BGSMaterialType.h"
#include "RE/B/BGSMenuIcon.h"
#include "RE/B/BGSMessage.h"
#include "RE/B/BGSMod.h"
#include "RE/B/BGSMovableStatic.h"
#include "RE/B/BGSMovementType.h"
#include "RE/B/BGSMusicTrackFormWrapper.h"
#include "RE/B/BGSMusicType.h"
#include "RE/B/BGSNote.h"
#include "RE/B/BGSOutfit.h"
#include "RE/B/BGSPackIn.h"
#include "RE/B/BGSPerk.h"
#include "RE/B/BGSProjectile.h"
#include "RE/B/BGSReferenceEffect.h"
#include "RE/B/BGSRelationship.h"
#include "RE/B/BGSReverbParameters.h"
#include "RE/B/BGSScene.h"
#include "RE/B/BGSShaderParticleGeometryData.h"
#include "RE/B/BGSSoundCategory.h"
#include "RE/B/BGSSoundCategorySnapshot.h"
#include "RE/B/BGSSoundDescriptorForm.h"
#include "RE/B/BGSSoundKeywordMapping.h"
#include "RE/B/BGSSoundOutput.h"
#include "RE/B/BGSSoundTagSet.h"
#include "RE/B/BGSStaticCollection.h"
#include "RE/B/BGSStoryManagerBranchNode.h"
#include "RE/B/BGSStoryManagerEventNode.h"
#include "RE/B/BGSStoryManagerQuestNode.h"
#include "RE/B/BGSTalkingActivator.h"
#include "RE/B/BGSTerminal.h"
#include "RE/B/BGSTextureSet.h"
#include "RE/B/BGSTransform.h"
#include "RE/B/BGSVoiceType.h"
#include "RE/B/BGSZoomData.h"
#include "RE/B/BarrierProjectile.h"
#include "RE/B/BeamProjectile.h"
#include "RE/C/ConeProjectile.h"
#include "RE/E/EffectSetting.h"
#include "RE/E/EnchantmentItem.h"
#include "RE/F/FlameProjectile.h"
#include "RE/G/GrenadeProjectile.h"
#include "RE/H/Hazard.h"
#include "RE/I/IngredientItem.h"
#include "RE/M/MissileProjectile.h"
#include "RE/N/NavMesh.h"
#include "RE/N/NavMeshInfoMap.h"
#include "RE/S/Script.h"
#include "RE/S/ScrollItem.h"
#include "RE/S/SpellItem.h"
#include "RE/T/TESAmmo.h"
#include "RE/T/TESClass.h"
#include "RE/T/TESClimate.h"
#include "RE/T/TESCombatStyle.h"
#include "RE/T/TESEffectShader.h"
#include "RE/T/TESEyes.h"
#include "RE/T/TESFaction.h"
#include "RE/T/TESFlora.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFurniture.h"
#include "RE/T/TESGlobal.h"
#include "RE/T/TESGrass.h"
#include "RE/T/TESIdleForm.h"
#include "RE/T/TESImageSpace.h"
#include "RE/T/TESImageSpaceModifier.h"
#include "RE/T/TESKey.h"
#include "RE/T/TESLandTexture.h"
#include "RE/T/TESLevCharacter.h"
#include "RE/T/TESLevItem.h"
#include "RE/T/TESLevSpell.h"
#include "RE/T/TESLoadScreen.h"
#include "RE/T/TESNPC.h"
#include "RE/T/TESObjectACTI.h"
#include "RE/T/TESObjectANIO.h"
#include "RE/T/TESObjectARMA.h"
#include "RE/T/TESObjectARMO.h"
#include "RE/T/TESObjectBOOK.h"
#include "RE/T/TESObjectCELL.h"
#include "RE/T/TESObjectCONT.h"
#include "RE/T/TESObjectDOOR.h"
#include "RE/T/TESObjectLAND.h"
#include "RE/T/TESObjectLIGH.h"
#include "RE/T/TESObjectMISC.h"
#include "RE/T/TESObjectREFR.h"
#include "RE/T/TESObjectSTAT.h"
#include "RE/T/TESObjectTREE.h"
#include "RE/T/TESObjectWEAP.h"
#include "RE/T/TESPackage.h"
#include "RE/T/TESQuest.h"
#include "RE/T/TESRace.h"
#include "RE/T/TESRegion.h"
#include "RE/T/TESShout.h"
#include "RE/T/TESSoulGem.h"
#include "RE/T/TESSound.h"
#include "RE/T/TESTopic.h"
#include "RE/T/TESTopicInfo.h"
#include "RE/T/TESWaterForm.h"
#include "RE/T/TESWeather.h"
#include "RE/T/TESWordOfPower.h"
#include "RE/T/TESWorldSpace.h"

#define F4SE_FORMUTIL(a_elem)                                           \
	case a_elem::FORM_ID:                                               \
		if constexpr (std::is_convertible_v<const a_elem*, const T*>) { \
			return static_cast<const a_elem*>(this);                    \
		}                                                               \
		break

namespace RE
{
	template <class T, class>
	[[nodiscard]] T* TESForm::As() noexcept
	{
		return const_cast<T*>(static_cast<const TESForm*>(this)->As<T>());
	}

	template <class T, class>
	[[nodiscard]] const T* TESForm::As() const noexcept
	{
		switch (GetFormType()) {
			F4SE_FORMUTIL(TESForm);
			F4SE_FORMUTIL(BGSKeyword);
			F4SE_FORMUTIL(BGSLocationRefType);
			F4SE_FORMUTIL(BGSAction);
			F4SE_FORMUTIL(BGSTransform);
			F4SE_FORMUTIL(BGSComponent);
			F4SE_FORMUTIL(BGSTextureSet);
			F4SE_FORMUTIL(BGSMenuIcon);
			F4SE_FORMUTIL(TESGlobal);
			F4SE_FORMUTIL(BGSDamageType);
			F4SE_FORMUTIL(TESClass);
			F4SE_FORMUTIL(TESFaction);
			F4SE_FORMUTIL(BGSHeadPart);
			F4SE_FORMUTIL(TESEyes);
			F4SE_FORMUTIL(TESRace);
			F4SE_FORMUTIL(TESSound);
			F4SE_FORMUTIL(BGSAcousticSpace);
			F4SE_FORMUTIL(EffectSetting);
			F4SE_FORMUTIL(Script);
			F4SE_FORMUTIL(TESLandTexture);
			F4SE_FORMUTIL(EnchantmentItem);
			F4SE_FORMUTIL(SpellItem);
			F4SE_FORMUTIL(ScrollItem);
			F4SE_FORMUTIL(TESObjectACTI);
			F4SE_FORMUTIL(BGSTalkingActivator);
			F4SE_FORMUTIL(TESObjectARMO);
			F4SE_FORMUTIL(TESObjectBOOK);
			F4SE_FORMUTIL(TESObjectCONT);
			F4SE_FORMUTIL(TESObjectDOOR);
			F4SE_FORMUTIL(IngredientItem);
			F4SE_FORMUTIL(TESObjectLIGH);
			F4SE_FORMUTIL(TESObjectMISC);
			F4SE_FORMUTIL(TESObjectSTAT);
			F4SE_FORMUTIL(BGSStaticCollection);
			F4SE_FORMUTIL(BGSMovableStatic);
			F4SE_FORMUTIL(TESGrass);
			F4SE_FORMUTIL(TESObjectTREE);
			F4SE_FORMUTIL(TESFlora);
			F4SE_FORMUTIL(TESFurniture);
			F4SE_FORMUTIL(TESObjectWEAP);
			F4SE_FORMUTIL(TESAmmo);
			F4SE_FORMUTIL(TESNPC);
			F4SE_FORMUTIL(TESLevCharacter);
			F4SE_FORMUTIL(TESKey);
			F4SE_FORMUTIL(AlchemyItem);
			F4SE_FORMUTIL(BGSIdleMarker);
			F4SE_FORMUTIL(BGSNote);
			F4SE_FORMUTIL(BGSProjectile);
			F4SE_FORMUTIL(BGSHazard);
			F4SE_FORMUTIL(BGSBendableSpline);
			F4SE_FORMUTIL(TESSoulGem);
			F4SE_FORMUTIL(BGSTerminal);
			F4SE_FORMUTIL(TESLevItem);
			F4SE_FORMUTIL(TESWeather);
			F4SE_FORMUTIL(TESClimate);
			F4SE_FORMUTIL(BGSShaderParticleGeometryData);
			F4SE_FORMUTIL(BGSReferenceEffect);
			F4SE_FORMUTIL(TESRegion);
			F4SE_FORMUTIL(NavMeshInfoMap);
			F4SE_FORMUTIL(TESObjectCELL);
			F4SE_FORMUTIL(TESObjectREFR);
			F4SE_FORMUTIL(Actor);
			F4SE_FORMUTIL(MissileProjectile);
			F4SE_FORMUTIL(ArrowProjectile);
			F4SE_FORMUTIL(GrenadeProjectile);
			F4SE_FORMUTIL(BeamProjectile);
			F4SE_FORMUTIL(FlameProjectile);
			F4SE_FORMUTIL(ConeProjectile);
			F4SE_FORMUTIL(BarrierProjectile);
			F4SE_FORMUTIL(Hazard);
			F4SE_FORMUTIL(TESWorldSpace);
			F4SE_FORMUTIL(TESObjectLAND);
			F4SE_FORMUTIL(NavMesh);
			F4SE_FORMUTIL(TESTopic);
			F4SE_FORMUTIL(TESTopicInfo);
			F4SE_FORMUTIL(TESQuest);
			F4SE_FORMUTIL(TESIdleForm);
			F4SE_FORMUTIL(TESPackage);
			F4SE_FORMUTIL(TESCombatStyle);
			F4SE_FORMUTIL(TESLoadScreen);
			F4SE_FORMUTIL(TESLevSpell);
			F4SE_FORMUTIL(TESObjectANIO);
			F4SE_FORMUTIL(TESWaterForm);
			F4SE_FORMUTIL(TESEffectShader);
			F4SE_FORMUTIL(BGSExplosion);
			F4SE_FORMUTIL(BGSDebris);
			F4SE_FORMUTIL(TESImageSpace);
			F4SE_FORMUTIL(TESImageSpaceModifier);
			F4SE_FORMUTIL(BGSListForm);
			F4SE_FORMUTIL(BGSPerk);
			F4SE_FORMUTIL(BGSBodyPartData);
			F4SE_FORMUTIL(BGSAddonNode);
			F4SE_FORMUTIL(ActorValueInfo);
			F4SE_FORMUTIL(BGSCameraShot);
			F4SE_FORMUTIL(BGSCameraPath);
			F4SE_FORMUTIL(BGSVoiceType);
			F4SE_FORMUTIL(BGSMaterialType);
			F4SE_FORMUTIL(BGSImpactData);
			F4SE_FORMUTIL(BGSImpactDataSet);
			F4SE_FORMUTIL(TESObjectARMA);
			F4SE_FORMUTIL(BGSEncounterZone);
			F4SE_FORMUTIL(BGSLocation);
			F4SE_FORMUTIL(BGSMessage);
			F4SE_FORMUTIL(BGSDefaultObjectManager);
			F4SE_FORMUTIL(BGSDefaultObject);
			F4SE_FORMUTIL(BGSLightingTemplate);
			F4SE_FORMUTIL(BGSMusicType);
			F4SE_FORMUTIL(BGSFootstep);
			F4SE_FORMUTIL(BGSFootstepSet);
			F4SE_FORMUTIL(BGSStoryManagerBranchNode);
			F4SE_FORMUTIL(BGSStoryManagerQuestNode);
			F4SE_FORMUTIL(BGSStoryManagerEventNode);
			F4SE_FORMUTIL(BGSDialogueBranch);
			F4SE_FORMUTIL(BGSMusicTrackFormWrapper);
			F4SE_FORMUTIL(TESWordOfPower);
			F4SE_FORMUTIL(TESShout);
			F4SE_FORMUTIL(BGSEquipSlot);
			F4SE_FORMUTIL(BGSRelationship);
			F4SE_FORMUTIL(BGSScene);
			F4SE_FORMUTIL(BGSAssociationType);
			F4SE_FORMUTIL(BGSOutfit);
			F4SE_FORMUTIL(BGSArtObject);
			F4SE_FORMUTIL(BGSMaterialObject);
			F4SE_FORMUTIL(BGSMovementType);
			F4SE_FORMUTIL(BGSSoundDescriptorForm);
			F4SE_FORMUTIL(BGSDualCastData);
			F4SE_FORMUTIL(BGSSoundCategory);
			F4SE_FORMUTIL(BGSSoundOutput);
			F4SE_FORMUTIL(BGSCollisionLayer);
			F4SE_FORMUTIL(BGSColorForm);
			F4SE_FORMUTIL(BGSReverbParameters);
			F4SE_FORMUTIL(BGSPackIn);
			F4SE_FORMUTIL(BGSAimModel);
			F4SE_FORMUTIL(BGSConstructibleObject);
			F4SE_FORMUTIL(BGSMod::Attachment::Mod);
			F4SE_FORMUTIL(BGSMaterialSwap);
			F4SE_FORMUTIL(BGSZoomData);
			F4SE_FORMUTIL(BGSInstanceNamingRules);
			F4SE_FORMUTIL(BGSSoundKeywordMapping);
			F4SE_FORMUTIL(BGSAudioEffectChain);
			F4SE_FORMUTIL(BGSAttractionRule);
			F4SE_FORMUTIL(BGSSoundCategorySnapshot);
			F4SE_FORMUTIL(BGSSoundTagSet);
			F4SE_FORMUTIL(BGSLensFlare);
			F4SE_FORMUTIL(BGSGodRays);
			default:
				break;
		}

		return nullptr;
	}
}

#undef F4SE_FORMUTIL
