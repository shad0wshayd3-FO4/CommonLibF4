#pragma once

#include "RE/Bethesda/BSContainer.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSStringT.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTHashMap.h"
#include "RE/Bethesda/BSTList.h"
#include "RE/Bethesda/BSTSmartPointer.h"
#include "RE/Bethesda/BSTTuple.h"
#include "RE/Bethesda/MemoryManager.h"
#include "RE/NetImmerse/NiPoint.h"
#include "RE/NetImmerse/NiRefObject.h"
#include "RE/NetImmerse/NiSmartPointer.h"

namespace RE
{
	class BaseFormComponent;
	class TESTexture;
	class TESIcon;
	class BGSAttachParentArray;
	class BGSAttackDataForm;
	class BGSBipedObjectForm;
	class BGSBlockBashData;
	class BGSCraftingUseSound;
	class BGSDestructibleObjectForm;
	class BGSEquipType;
	class BGSFeaturedItemMessage;
	class BGSForcedLocRefType;
	class BGSIdleCollection;
	class BGSInstanceNamingRulesForm;
	class BGSKeywordForm;
	class BGSMenuDisplayObject;
	class BGSMessageIcon;
	class BGSNativeTerminalForm;
	class BGSOverridePackCollection;
	class BGSPerkRankArray;
	class BGSPickupPutdownSounds;
	class BGSPreloadable;
	class BGSPreviewTransform;
	class BGSPropertySheet;
	class BGSSkinForm;
	class BGSSoundTagComponent;
	class TESContainer;
	class TESDescription;
	class TESEnchantableForm;
	class TESFullName;
	class TESModel;
	class BGSBehaviorGraphModel;
	class BGSModelMaterialSwap;
	class BGSTextureModel;
	class TESModelRDT;
	class TESActorBaseData;
	class TESAIForm;
	class TESBipedModelForm;
	class TESImageSpaceModifiableForm;
	class TESLeveledList;
	class TESModelTri;
	class TESProduceForm;
	class TESRaceForm;
	class TESReactionForm;
	class TESSpellList;
	class TESTexture1024;
	class TESValueForm;
	class TESWeightForm;

	namespace BGSMod::Template
	{
		class Item;
		class Items;
	}

	enum class ENUM_FORM_ID;
	enum class IO_TASK_PRIORITY;

	class ActorValueInfo;
	class ActorValueOwner;
	class BGSDebris;
	class BGSEquipSlot;
	class BGSExplosion;
	class BGSImpactDataSet;
	class BGSInstanceNamingRules;
	class BGSKeyword;
	class BGSListForm;
	class BGSLocationRefType;
	class BGSMaterialSwap;
	class BGSMaterialType;
	class BGSMessage;
	class BGSPerk;
	class BGSSoundDescriptorForm;
	class BGSTerminal;
	class BGSTransform;
	class BGSVoiceType;
	class BSIAudioEffectVisitorBase;
	class EnchantmentItem;
	class NavMesh;
	class NiAVObject;
	class NiProperty;
	class QueuedFile;
	class SpellItem;
	class TBO_InstanceData;
	class TESActorBase;
	class TESBoundObject;
	class TESFaction;
	class TESFile;
	class TESForm;
	class TESGlobal;
	class TESIdleForm;
	class TESImageSpaceModifier;
	class TESLevItem;
	class TESLevSpell;
	class TESObjectARMO;
	class TESObjectCELL;
	class TESObjectREFR;
	class TESPackage;
	class TESRace;
	class TESRegion;
	class TESShout;

	namespace BSISoundCategoryUtils
	{
		enum class FadeType;
	}

	namespace BSResource
	{
		struct ID;
	}

	namespace MagicSystem
	{
		enum class CastingType;
	}

	namespace BGSTypedFormValuePair
	{
		union SharedVal
		{
			std::uint32_t i;
			float         f;
		};
		static_assert(sizeof(SharedVal) == 0x4);
	}

	enum class ACTOR_VALUE_MODIFIER
	{
		kPermanent = 0,
		kTemporary = 1,
		kDamage = 2
	};

	class __declspec(novtable) ActorValueOwner
	{
	public:
		static constexpr auto RTTI{ RTTI::ActorValueOwner };
		static constexpr auto VTABLE{ VTABLE::ActorValueOwner };

		virtual ~ActorValueOwner() = default;  // 00

		// add
		virtual float GetActorValue([[maybe_unused]] const ActorValueInfo& a_info) const { return 0.0F; }                                                                         // 01
		virtual float GetPermanentActorValue([[maybe_unused]] const ActorValueInfo& a_info) const { return 0.0F; }                                                                // 02
		virtual float GetBaseActorValue([[maybe_unused]] const ActorValueInfo& a_info) const { return 0.0F; }                                                                     // 03
		virtual void  SetBaseActorValue([[maybe_unused]] const ActorValueInfo& a_info, [[maybe_unused]] float a_value) { return; }                                                // 04
		virtual void  ModBaseActorValue([[maybe_unused]] const ActorValueInfo& a_info, [[maybe_unused]] float a_delta) { return; }                                                // 05
		virtual void  ModActorValue([[maybe_unused]] ACTOR_VALUE_MODIFIER a_modifier, [[maybe_unused]] const ActorValueInfo& a_info, [[maybe_unused]] float a_delta) { return; }  // 06
		virtual float GetModifier([[maybe_unused]] ACTOR_VALUE_MODIFIER a_modifier, [[maybe_unused]] const ActorValueInfo& a_info) const { return 0.0F; }                         // 07
		virtual void  RestoreActorValue([[maybe_unused]] const ActorValueInfo& a_info, [[maybe_unused]] float a_amount) { return; }                                               // 08
		virtual void  SetActorValue(const ActorValueInfo& a_info, float a_value) { SetBaseActorValue(a_info, a_value); }                                                          // 09
		virtual bool  GetIsPlayerOwner() const { return false; }                                                                                                                  // 0A
	};
	static_assert(sizeof(ActorValueOwner) == 0x8);

	class BGSDirectionalAmbientLightingColors
	{
	public:
		// members
		std::uint32_t colorValues[7];  // 00
		float         fresnelPower;    // 1C
	};
	static_assert(sizeof(BGSDirectionalAmbientLightingColors) == 0x20);

	class BGSNavmeshableObject
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSNavmeshableObject };

		// members
		BSTSmartPointer<NavMesh> embeddedNavmesh;  // 0
	};
	static_assert(sizeof(BGSNavmeshableObject) == 0x8);

	class __declspec(novtable) BGSOpenCloseForm
	{
	public:
		inline static constexpr auto RTTI{ RTTI::BGSOpenCloseForm };
		inline static constexpr auto VTABLE{ VTABLE::BGSOpenCloseForm };

		enum class OPEN_STATE : std::int32_t
		{
			kNone = 0,
			kOpen = 1,
			kOpening = 2,
			kClosed = 3,
			kClosing = 4
		};

		virtual ~BGSOpenCloseForm() = default;  // 00

		// add
		virtual void HandleOpenStart(TESObjectREFR*, TESObjectREFR*, bool) { return; }   // 01
		virtual void HandleCloseStart(TESObjectREFR*, TESObjectREFR*, bool) { return; }  // 02
		virtual void HandleOpenFinish(TESObjectREFR*, TESObjectREFR*) { return; }        // 03
		virtual void HandleCloseFinish(TESObjectREFR*, TESObjectREFR*) { return; }       // 04

		inline static void AutoCloseRef(const TESObjectREFR* a_ref)
		{
			using func_t = decltype(&BGSOpenCloseForm::AutoCloseRef);
			static REL::Relocation<func_t> func{ REL::ID(2192797) };
			func(a_ref);
		}

		inline static OPEN_STATE GetOpenState(const TESObjectREFR* a_ref)
		{
			using func_t = decltype(&BGSOpenCloseForm::GetOpenState);
			static REL::Relocation<func_t> func{ REL::ID(2192799) };
			return func(a_ref);
		}

		inline static bool HasOnlyOpenCloseAnims(const TESObjectREFR* a_ref)
		{
			using func_t = decltype(&BGSOpenCloseForm::HasOnlyOpenCloseAnims);
			static REL::Relocation<func_t> func{ REL::ID(2192796) };
			return func(a_ref);
		}

		inline static bool IsAnimating(const TESObjectREFR* a_ref)
		{
			using func_t = decltype(&BGSOpenCloseForm::IsAnimating);
			static REL::Relocation<func_t> func{ REL::ID(2192801) };
			return func(a_ref);
		}

		inline static bool IsOpenCloseEvent(const BSFixedString& a_event, const bool& a_open)
		{
			using func_t = decltype(&BGSOpenCloseForm::IsOpenCloseEvent);
			static REL::Relocation<func_t> func{ REL::ID(2192795) };
			return func(a_event, a_open);
		}

		inline static bool IsOpenCloseForm(TESForm* a_form)
		{
			using func_t = decltype(&BGSOpenCloseForm::IsOpenCloseForm);
			static REL::Relocation<func_t> func{ REL::ID(2192790) };
			return func(a_form);
		}

		inline static bool SetOpenState(const TESObjectREFR* a_ref, bool a_open, bool a_snap)
		{
			using func_t = decltype(&BGSOpenCloseForm::SetOpenState);
			static REL::Relocation<func_t> func{ REL::ID(2192798) };
			return func(a_ref, a_open, a_snap);
		}
	};
	static_assert(sizeof(BGSOpenCloseForm) == 0x8);

	class __declspec(novtable) BSIAudioEffectChain
	{
	public:
		static constexpr auto RTTI{ RTTI::BSIAudioEffectChain };
		static constexpr auto VTABLE{ VTABLE::BSIAudioEffectChain };

		virtual ~BSIAudioEffectChain() = default;  // 00

		// add
		virtual std::uint32_t QEffectCount() const = 0;                                                 // 01
		virtual char const*   GetDebugID() const = 0;                                                   // 02
		virtual void          ForEachEffectImpl(const BSIAudioEffectVisitorBase& a_visitor) const = 0;  // 03
	};
	static_assert(sizeof(BSIAudioEffectChain) == 0x8);

	class __declspec(novtable) BSIMusicTrack
	{
	public:
		static constexpr auto RTTI{ RTTI::BSIMusicTrack };
		static constexpr auto VTABLE{ VTABLE::BSIMusicTrack };

		enum class MUSIC_STATUS;

		virtual ~BSIMusicTrack() = default;  // 00

		// add
		virtual void          DoUpdate() = 0;                                                                // 01
		virtual void          DoPlay() = 0;                                                                  // 02
		virtual void          DoPause() = 0;                                                                 // 03
		virtual void          DoFinish(bool a_immediate, float a_fadeTime) = 0;                              // 04
		virtual float         GetDurationImpl() const = 0;                                                   // 05
		virtual std::uint32_t GetType() const = 0;                                                           // 06
		virtual bool          TestCanPlay() const { return true; }                                           // 07
		virtual MUSIC_STATUS  GetMusicStatus() const { return *trackStatus; }                                // 08
		virtual void          DoSetDuckingAttenuation([[maybe_unused]] std::uint16_t a_ducking) { return; }  // 09
		virtual void          DoClearDucking() { return; }                                                   // 0A

		// members
		REX::EnumSet<MUSIC_STATUS, std::int32_t> trackStatus;  // 08
	};
	static_assert(sizeof(BSIMusicTrack) == 0x10);

	class __declspec(novtable) BSIMusicType
	{
	public:
		static constexpr auto RTTI{ RTTI::BSIMusicType };
		static constexpr auto VTABLE{ VTABLE::BSIMusicType };

		// add
		virtual void DoUpdate() = 0;                                                                  // 00
		virtual void DoPlay() = 0;                                                                    // 01
		virtual void DoPause() = 0;                                                                   // 02
		virtual void DoFinish(bool a_immediate) = 0;                                                  // 03
		virtual void DoApplyDuckingAttenuation([[maybe_unused]] std::uint16_t a_ducking) { return; }  // 04
		virtual void DoClearDucking() { return; }                                                     // 05
		virtual void DoPrepare() { return; }                                                          // 06

		virtual ~BSIMusicType();  // 07

		// members
		std::uint32_t                                           flags;              // 08
		std::int8_t                                             priority;           // 0C
		std::int8_t                                             padding;            // 0D
		std::uint16_t                                           ducksOtherMusicBy;  // 0E
		float                                                   fadeTime;           // 10
		std::uint32_t                                           currentTrackIndex;  // 14
		BSTArray<std::uint32_t>                                 trackHistory;       // 18
		BSTArray<BSIMusicTrack*>                                tracks;             // 30
		REX::EnumSet<BSIMusicTrack::MUSIC_STATUS, std::int32_t> typeStatus;         // 48
	};
	static_assert(sizeof(BSIMusicType) == 0x50);

	class __declspec(novtable) BSIReverbType
	{
	public:
		static constexpr auto RTTI{ RTTI::BSIReverbType };
		static constexpr auto VTABLE{ VTABLE::BSIReverbType };

		// add
		virtual std::int32_t DoGetRoomLevel() const = 0;        // 00
		virtual std::int32_t DoGetRoomHFLevel() const = 0;      // 01
		virtual float        DoGetDecayTime() const = 0;        // 02
		virtual float        DoGetDecayHFRatio() const = 0;     // 03
		virtual std::int32_t DoGetReflectionLevel() const = 0;  // 04
		virtual float        DoGetReflectionDelay() const = 0;  // 05
		virtual std::int32_t DoGetReverbLevel() const = 0;      // 06
		virtual float        DoGetReverbDelay() const = 0;      // 07
		virtual float        DoGetDiffusion() const = 0;        // 08
		virtual float        DoGetDensity() const = 0;          // 09
		virtual float        DoGetHFReference() const = 0;      // 0A
	};
	static_assert(sizeof(BSIReverbType) == 0x8);

	class __declspec(novtable) BSISoundCategory
	{
	public:
		static constexpr auto RTTI{ RTTI::BSISoundCategory };
		static constexpr auto VTABLE{ VTABLE::BSISoundCategory };

		virtual ~BSISoundCategory() = default;  // 00

		// add
		virtual bool          Matches(BSISoundCategory* a_toCheck, bool a_exclusive) const = 0;                                 // 01
		virtual float         GetCategoryVolume() const = 0;                                                                    // 02
		virtual void          SetCategoryVolume(float a_newVolume) = 0;                                                         // 03
		virtual float         GetCategoryFrequency() const = 0;                                                                 // 04
		virtual void          SetCategoryFrequency(float a_newFreq) = 0;                                                        // 05
		virtual std::uint16_t GetCategoryAttenuation(BSISoundCategoryUtils::FadeType a_type) const = 0;                         // 06
		virtual void          SetCategoryAttenuation(BSISoundCategoryUtils::FadeType a_type, std::uint16_t a_attenuation) = 0;  // 07
		virtual bool          CategoryPaused() const = 0;                                                                       // 08
		virtual void          SetCategoryPaused(bool a_paused, bool a_exclusive) = 0;                                           // 09
		virtual bool          CategoryMute() const = 0;                                                                         // 0A
		virtual void          SetCategoryMute(bool a_mute, bool a_exclusive) = 0;                                               // 0B
		virtual float         GetMinFrequencyMult() const = 0;                                                                  // 0C
		virtual bool          GetBlockSpeedChange() const = 0;                                                                  // 0D
		virtual bool          GetSkipOPMOverrides() const = 0;                                                                  // 0E
		virtual const char*   GetDebugID() const = 0;                                                                           // 0F
	};
	static_assert(sizeof(BSISoundCategory) == 0x8);

	class __declspec(novtable) BSISoundDescriptor
	{
	public:
		static constexpr auto RTTI{ RTTI::BSISoundDescriptor };
		static constexpr auto VTABLE{ VTABLE::BSISoundDescriptor };

		struct ExtraResolutionData;
		struct Resolution;

		virtual ~BSISoundDescriptor() = default;  // 00

		// add
		virtual bool DoResolve(Resolution& a_resolution, float a_distance, ExtraResolutionData* a_data) const = 0;   // 01
		virtual bool DoMultiResolve(BSScrapArray<Resolution>& a_resolution, ExtraResolutionData* a_data) const = 0;  // 02
		virtual bool DoAudibilityTest(float a_distance) const = 0;                                                   // 03
		virtual bool DoGetMultiResolves() const = 0;                                                                 // 04
	};
	static_assert(sizeof(BSISoundDescriptor) == 0x8);

	class __declspec(novtable) BSISoundOutputModel
	{
	public:
		static constexpr auto RTTI{ RTTI::BSISoundOutputModel };
		static constexpr auto VTABLE{ VTABLE::BSISoundOutputModel };

		struct BSIAttenuationCharacteristics;

		virtual ~BSISoundOutputModel() = default;  // 00

		// add
		virtual bool                                 DoGetUsesHRTF() const = 0;                                                                               // 01
		virtual bool                                 DoGetHasSpeakerBias() const = 0;                                                                         // 02
		virtual bool                                 DoGetSpeakerBias(std::uint32_t a_srcChannels, std::uint32_t a_channel, float (&a_levels)[8]) const = 0;  // 03
		virtual bool                                 DoGetAttenuatesWithDistance() const = 0;                                                                 // 04
		virtual bool                                 DoGetUseDoppler() const = 0;                                                                             // 05
		virtual bool                                 DoGetUseSoSDelay() const = 0;                                                                            // 06
		virtual bool                                 DoGetAudibility(float a_distance) const = 0;                                                             // 07
		virtual std::uint32_t                        DoGetSupportedInputChannels() const = 0;                                                                 // 08
		virtual const BSIAttenuationCharacteristics* DoGetAttenuation() const = 0;                                                                            // 09
		virtual float                                DoGetReverbSendLevel() const = 0;                                                                        // 0A
		virtual bool                                 DoGetSupportsMonitor(std::uint32_t a_monitorID) const = 0;                                               // 0B
		virtual std::uint16_t                        DoGetStaticAttenuation() const = 0;                                                                      // 0C
		virtual const BSIAudioEffectChain*           DoGetEffectChain() const = 0;                                                                            // 0D
		virtual const char*                          DoGetDebugID() const = 0;                                                                                // 0E
		virtual bool                                 DoGetTryPlayThroughController() const = 0;                                                               // 0F
	};
	static_assert(sizeof(BSISoundOutputModel) == 0x8);

	class __declspec(novtable) BSMaterialObject
	{
	public:
		static constexpr auto RTTI{ RTTI::BSMaterialObject };
		static constexpr auto VTABLE{ VTABLE::BSMaterialObject };

		struct DIRECTIONAL_DATA
		{
		public:
			// members
			float        falloffScale;     // 00
			float        falloffBias;      // 04
			float        noiseUVScale;     // 08
			float        materialUVScale;  // 0C
			NiPoint3     projectionDir;    // 10
			float        normalDampener;   // 1C
			float        red;              // 20
			float        green;            // 24
			float        blue;             // 28
			std::int32_t singlePass;       // 2C
		};
		static_assert(sizeof(DIRECTIONAL_DATA) == 0x30);

		virtual ~BSMaterialObject();  // 00

		// add
		virtual void EnsureLoaded() { return; }  // 01

		// members
		DIRECTIONAL_DATA                directionalData;  // 08
		BSTArray<NiPointer<NiProperty>> property;         // 38
	};
	static_assert(sizeof(BSMaterialObject) == 0x50);

	struct INTERIOR_DATA
	{
	public:
		// members
		std::uint32_t                       ambient;                           // 00
		std::uint32_t                       directional;                       // 04
		std::uint32_t                       fogColorNear;                      // 08
		float                               fogNear;                           // 0C
		float                               fogFar;                            // 10
		std::uint32_t                       directionalXY;                     // 14
		std::uint32_t                       directionalZ;                      // 18
		float                               directionalFade;                   // 1C
		float                               clipDist;                          // 20
		float                               fogPower;                          // 24
		BGSDirectionalAmbientLightingColors directionalAmbientLightingColors;  // 28
		std::uint32_t                       fogColorFar;                       // 48
		float                               fogClamp;                          // 4C
		float                               lightFadeStart;                    // 50
		float                               lightFadeEnd;                      // 54
		std::uint32_t                       lightingTemplateInheritanceFlags;  // 58
		float                               fogHeightMid;                      // 5C
		float                               fogHeightRange;                    // 60
		std::uint32_t                       fogColorHighNear;                  // 64
		std::uint32_t                       fogColorHighFar;                   // 68
		float                               fogHighDensityScale;               // 6C
		float                               fogNearColorScale;                 // 70
		float                               fogFarColorScale;                  // 74
		float                               fogHighNearColorScale;             // 78
		float                               fogHighFarColorScale;              // 7C
		float                               fogFarHeightMid;                   // 80
		float                               fogFarHeightRange;                 // 84
		std::uint32_t                       interiorOffset;                    // 88
	};
	static_assert(sizeof(INTERIOR_DATA) == 0x8C);

	struct __declspec(novtable) TESChildCell
	{
	public:
		static constexpr auto RTTI{ RTTI::TESChildCell };
		static constexpr auto VTABLE{ VTABLE::TESChildCell };

		virtual ~TESChildCell() = default;  // 00

		// add
		virtual TESObjectCELL* GetSaveParentCell() const = 0;  // 01
	};
	static_assert(sizeof(TESChildCell) == 0x8);

	class TESMagicCasterForm
	{
	public:
		static constexpr auto RTTI{ RTTI::TESMagicCasterForm };
	};
	static_assert(std::is_empty_v<TESMagicCasterForm>);

	class TESMagicTargetForm
	{
	public:
		static constexpr auto RTTI{ RTTI::TESMagicTargetForm };
	};
	static_assert(std::is_empty_v<TESMagicTargetForm>);

	class __declspec(novtable) TBO_InstanceData :
		public BSIntrusiveRefCounted  // 08
	{
	public:
		static constexpr auto RTTI{ RTTI::TBO_InstanceData };
		static constexpr auto VTABLE{ VTABLE::TBO_InstanceData };

		virtual ~TBO_InstanceData() = default;  // 00

		// add
		virtual BGSKeywordForm*             GetKeywordData() const { return nullptr; }                                    // 01
		virtual void                        DeleteKeywordData() { return; }                                               // 02
		virtual void                        CreateKeywordData() { return; }                                               // 03
		virtual BGSBlockBashData*           GetBlockBashData() const { return nullptr; }                                  // 04
		virtual void                        DeleteBlockBashData() { return; }                                             // 05
		virtual void                        CreateBlockBashData() { return; }                                             // 06
		virtual BSTArray<EnchantmentItem*>* GetEnchantmentArray() const { return nullptr; }                               // 07
		virtual void                        DeleteEnchantmentArray() { return; }                                          // 08
		virtual void                        CreateEnchantmentArray() { return; }                                          // 09
		virtual BSTArray<BGSMaterialSwap*>* GetMaterialSwapArray() const { return nullptr; }                              // 0A
		virtual void                        DeleteMaterialSwapArray() { return; }                                         // 0B
		virtual void                        CreateMaterialSwapArray() { return; }                                         // 0C
		virtual float                       GetWeight() const { return -1.0F; }                                           // 0D
		virtual std::int32_t                GetValue() const { return -1; }                                               // 0E
		virtual std::uint32_t               GetHealth() const { return 0; }                                               // 0F
		virtual float                       GetColorRemappingIndex() const { return std::numeric_limits<float>::max(); }  // 10
		virtual void                        PostAttach3D(NiAVObject* a_obj3D, TESObjectREFR* a_ref) const;                // 11
		virtual void                        PostApplyMods(const TESBoundObject*) { return; }                              // 12
	};
	static_assert(sizeof(TBO_InstanceData) == 0x10);

	class __declspec(novtable) BaseFormComponent
	{
	public:
		static constexpr auto RTTI{ RTTI::BaseFormComponent };
		static constexpr auto VTABLE{ VTABLE::BaseFormComponent };

		virtual ~BaseFormComponent() = default;  // 00

		F4_HEAP_REDEFINE_NEW(BaseFormComponent);

		// add
		virtual std::uint32_t GetFormComponentType() const { return 0; }                                                                // 01
		virtual void          InitializeDataComponent() = 0;                                                                            // 02
		virtual void          ClearDataComponent() = 0;                                                                                 // 03
		virtual void          InitComponent() { return; }                                                                               // 04
		virtual void          CopyComponent([[maybe_unused]] BaseFormComponent* a_copy) { return; }                                     // 06
		virtual void          CopyComponent([[maybe_unused]] BaseFormComponent* a_copy, [[maybe_unused]] TESForm* a_owner) { return; }  // 05
	};
	static_assert(sizeof(BaseFormComponent) == 0x8);

	class __declspec(novtable) TESTexture :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESTexture };
		static constexpr auto VTABLE{ VTABLE::TESTexture };

		// override (BaseFormComponent)
		void InitializeDataComponent() override;          // 02
		void ClearDataComponent() override { return; }    // 03
		void CopyComponent(BaseFormComponent*) override;  // 06

		// add
		virtual std::uint32_t GetMaxAllowedSize() { return 0; }                       // 07
		virtual const char*   GetAsNormalFile(BSStringT<char>& a_outFilename) const;  // 08
		virtual const char*   GetDefaultPath() const { return "Textures\\"; }         // 09

		// members
		BSFixedString textureName;  // 08
	};
	static_assert(sizeof(TESTexture) == 0x10);

	class __declspec(novtable) TESIcon :
		public TESTexture  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESIcon };
		static constexpr auto VTABLE{ VTABLE::TESIcon };
	};
	static_assert(sizeof(TESIcon) == 0x10);

	enum class KeywordType
	{
		kNone = 0x0,
		kComponentTechLevel = 0x1,
		kAttachPoint = 0x2,
		kComponentProperty = 0x3,
		kInstantiationFilter = 0x4,
		kModAssociation = 0x5,
		kSound = 0x6,
		kAnimArchetype = 0x7,
		kFunctionCall = 0x8,
		kRecipeFilter = 0x9,
		kAttractionType = 0xA,
		kDialogueSubtype = 0xB,
		kQuestTarget = 0xC,
		kAnimFlavor = 0xD,
		kAnimGender = 0xE,
		kAnimFaceArchetype = 0xF,
		kQuestGroup = 0x10,
		kAnimInjured = 0x11,
		kDispelEffect = 0x12,

		kTotal = 0x13
	};

	template <KeywordType TYPE>
	class BGSTypedKeywordValue
	{
	public:
		// members
		std::uint16_t keywordIndex;  // 0
	};

	namespace detail
	{
		[[nodiscard]] BGSKeyword*   BGSKeywordGetTypedKeywordByIndex(KeywordType a_type, std::uint16_t a_index);
		[[nodiscard]] std::uint16_t BGSKeywordGetIndexForTypedKeyword(BGSKeyword* a_keyword, KeywordType a_type);
	}

	template <KeywordType TYPE>
	class BGSTypedKeywordValueArray
	{
	public:
		void AddKeyword(BGSKeyword* a_keyword)
		{
			if (a_keyword && !HasKeyword(a_keyword)) {
				MemoryManager&              mm = MemoryManager::GetSingleton();
				BGSTypedKeywordValue<TYPE>* newArray = (BGSTypedKeywordValue<TYPE>*)mm.Allocate(2 * (size + 1), 0, false);
				for (int i = 0; i < size; ++i) {
					newArray[i] = array[i];
				}
				BGSTypedKeywordValue<TYPE> newValue;
				newValue.keywordIndex = detail::BGSKeywordGetIndexForTypedKeyword(a_keyword, BGSKeyword::KeywordType::kAttachPoint);
				newArray[size] = newValue;
				mm.Deallocate(array, false);
				array = newArray;
				++size;
			}
		}

		[[nodiscard]] bool HasKeyword(BGSKeyword* a_keyword)
		{
			for (std::uint32_t i = 0; i < size; ++i) {
				const auto kywd = detail::BGSKeywordGetTypedKeywordByIndex(TYPE, array[i].keywordIndex);
				if (kywd == a_keyword) {
					return true;
				}
			}
			return false;
		}

		// members
		BGSTypedKeywordValue<TYPE>* array;  // 00
		std::uint32_t               size;   // 08
	};

	class __declspec(novtable) BGSAttachParentArray :
		public BaseFormComponent,                                    // 00
		public BGSTypedKeywordValueArray<KeywordType::kAttachPoint>  // 08
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSAttachParentArray };
		static constexpr auto VTABLE{ VTABLE::BGSAttachParentArray };

		// override (BaseFormComponent)
		std::uint32_t GetFormComponentType() const override { return 'APPA'; }  // 01
		void          InitializeDataComponent() override { return; }            // 02
		void          ClearDataComponent() override;                            // 03
		void          CopyComponent(BaseFormComponent*) override { return; }    // 06
		void          CopyComponent(BaseFormComponent*, TESForm*) override;     // 05

		void SetParentGroupNumber(BGSKeyword* a_parent, std::uint32_t a_groupID)
		{
			using func_t = decltype(&BGSAttachParentArray::SetParentGroupNumber);
			static REL::Relocation<func_t> func{ REL::ID(1412266) };
			return func(this, a_parent, a_groupID);
		}
	};
	static_assert(sizeof(BGSAttachParentArray) == 0x18);

	struct AttackData
	{
	public:
		// members
		float         damageMult;        // 00
		float         attackChance;      // 04
		SpellItem*    attackSpell;       // 08
		std::uint32_t flags;             // 10
		float         attackAngle;       // 14
		float         strikeAngle;       // 18
		std::int32_t  staggerOffset;     // 1C
		BGSKeyword*   attackType;        // 20
		float         knockdown;         // 28
		float         recoveryTime;      // 2C
		float         actionPointsMult;  // 30
	};
	static_assert(sizeof(AttackData) == 0x38);

	class __declspec(novtable) BGSAttackData :
		public NiRefObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSAttackData };
		static constexpr auto VTABLE{ VTABLE::BGSAttackData };

		// members
		BSFixedString event;              // 10
		AttackData    data;               // 18
		BGSEquipSlot* weaponEquipSlot;    // 50
		BGSEquipSlot* requiredEquipSlot;  // 58
	};
	static_assert(sizeof(BGSAttackData) == 0x60);

	class __declspec(novtable) BGSAttackDataMap :
		public NiRefObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSAttackDataMap };
		static constexpr auto VTABLE{ VTABLE::BGSAttackDataMap };

		// members
		BSTHashMap<BSFixedString, NiPointer<BGSAttackData>> attackDataMap;    // 10
		TESRace*                                            defaultDataRace;  // 40
	};
	static_assert(sizeof(BGSAttackDataMap) == 0x48);

	class __declspec(novtable) BGSAttackDataForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSAttackDataForm };
		static constexpr auto VTABLE{ VTABLE::BGSAttackDataForm };

		// members
		NiPointer<BGSAttackDataMap> attackDataMap;  // 08
	};
	static_assert(sizeof(BGSAttackDataForm) == 0x10);

	struct __declspec(novtable) BIPED_MODEL
	{
	public:
		// members
		std::uint32_t bipedObjectSlots;  // 0
	};
	static_assert(sizeof(BIPED_MODEL) == 0x4);

	class __declspec(novtable) BGSBipedObjectForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSBipedObjectForm };
		static constexpr auto VTABLE{ VTABLE::BGSBipedObjectForm };

		// add
		virtual bool FillsBipedSlot(std::int32_t a_bipedSlot) const;  // 06

		// members
		BIPED_MODEL bipedModelData;  // 08
	};
	static_assert(sizeof(BGSBipedObjectForm) == 0x10);

	class __declspec(novtable) BGSBlockBashData :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSBlockBashData };
		static constexpr auto VTABLE{ VTABLE::BGSBlockBashData };

		// members
		BGSImpactDataSet* blockBashImpactDataSet;  // 08
		BGSMaterialType*  altBlockMaterialType;    // 10
	};
	static_assert(sizeof(BGSBlockBashData) == 0x18);

	class __declspec(novtable) BGSCraftingUseSound :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSCraftingUseSound };
		static constexpr auto VTABLE{ VTABLE::BGSCraftingUseSound };

		// members
		BGSSoundDescriptorForm* craftingUseSound;  // 08
	};
	static_assert(sizeof(BGSCraftingUseSound) == 0x10);

	class DestructibleObjectStage
	{
	public:
		// members
		std::int8_t           modelDamageStage;     // 00
		std::int8_t           healthPercentage;     // 01
		std::int8_t           flags;                // 02
		std::uint32_t         selfDamagePerSecond;  // 04
		BGSExplosion*         explosion;            // 08
		BGSDebris*            debris;               // 10
		std::uint32_t         debrisCount;          // 18
		BGSModelMaterialSwap* replacementModel;     // 20
		BSFixedString         sequenceName;         // 28
	};
	static_assert(sizeof(DestructibleObjectStage) == 0x30);

	struct DestructibleObjectData
	{
	public:
		// members
		std::uint32_t                                                   health;                      // 00
		std::int8_t                                                     numStages;                   // 04
		std::int8_t                                                     flags;                       // 05
		DestructibleObjectStage**                                       stagesArray;                 // 08
		BSTArray<BSTTuple<TESForm*, BGSTypedFormValuePair::SharedVal>>* damageTypes;                 // 10
		volatile std::int32_t                                           replacementModelRefCount;    // 18
		NiPointer<QueuedFile>                                           preloadedReplacementModels;  // 20
	};
	static_assert(sizeof(DestructibleObjectData) == 0x28);

	class __declspec(novtable) BGSDestructibleObjectForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSDestructibleObjectForm };
		static constexpr auto VTABLE{ VTABLE::BGSDestructibleObjectForm };

		// members
		DestructibleObjectData* data;  // 08
	};
	static_assert(sizeof(BGSDestructibleObjectForm) == 0x10);

	class __declspec(novtable) BGSEquipType :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSEquipType };
		static constexpr auto VTABLE{ VTABLE::BGSEquipType };

		// add
		[[nodiscard]] virtual BGSEquipSlot* GetEquipSlot([[maybe_unused]] const TBO_InstanceData* a_data) const { return equipSlot; }  // 06
		virtual void                        SetEquipSlot(BGSEquipSlot* a_slot) { equipSlot = a_slot; }                                 // 07

		// members
		BGSEquipSlot* equipSlot;  // 08
	};
	static_assert(sizeof(BGSEquipType) == 0x10);

	class __declspec(novtable) BGSFeaturedItemMessage :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSFeaturedItemMessage };
		static constexpr auto VTABLE{ VTABLE::BGSFeaturedItemMessage };

		// members
		BGSMessage* featuredItemMessage;  // 08
	};
	static_assert(sizeof(BGSFeaturedItemMessage) == 0x10);

	class __declspec(novtable) BGSForcedLocRefType :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSForcedLocRefType };
		static constexpr auto VTABLE{ VTABLE::BGSForcedLocRefType };

		// members
		BGSLocationRefType* forcedType;  // 08
	};
	static_assert(sizeof(BGSForcedLocRefType) == 0x10);

	class __declspec(novtable) BGSIdleCollection :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSIdleCollection };
		static constexpr auto VTABLE{ VTABLE::BGSIdleCollection };

		// members
		std::int8_t   idleFlags;          // 08
		std::int8_t   idleCount;          // 09
		TESIdleForm** idleArray;          // 10
		float         timerCheckForIdle;  // 18
	};
	static_assert(sizeof(BGSIdleCollection) == 0x20);

	class __declspec(novtable) BGSInstanceNamingRulesForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSInstanceNamingRulesForm };
		static constexpr auto VTABLE{ VTABLE::BGSInstanceNamingRulesForm };

		// members
		BGSInstanceNamingRules* instanceNamingRules;  // 08
	};
	static_assert(sizeof(BGSInstanceNamingRulesForm) == 0x10);

	class __declspec(novtable) IKeywordFormBase
	{
	public:
		static constexpr auto RTTI{ RTTI::IKeywordFormBase };
		static constexpr auto VTABLE{ VTABLE::IKeywordFormBase };

		virtual ~IKeywordFormBase() = default;  // 00

		// add
		virtual bool HasKeyword(const BGSKeyword* a_keyword, const TBO_InstanceData* a_data = nullptr) const = 0;                   // 01
		virtual void CollectAllKeywords(BSScrapArray<const BGSKeyword*>& a_outKeywords, const TBO_InstanceData* a_data) const = 0;  // 02
	};
	static_assert(sizeof(IKeywordFormBase) == 0x8);

	class __declspec(novtable) BGSKeywordForm :
		public BaseFormComponent,  // 00
		public IKeywordFormBase    // 08
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSKeywordForm };
		static constexpr auto VTABLE{ VTABLE::BGSKeywordForm };

		// override (BaseFormComponent)
		void InitializeDataComponent() override { return; }  // 02
		void ClearDataComponent() override;                  // 03
		void InitComponent() override { return; }            // 04
		void CopyComponent(BaseFormComponent*) override;     // 06

		// override (IKeywordFormBase)
		bool HasKeyword(const BGSKeyword* a_keyword, const TBO_InstanceData* a_data = nullptr) const override;  // 01
		void CollectAllKeywords(BSScrapArray<const BGSKeyword*>&, const TBO_InstanceData*) const override;      // 02

		// add
		virtual BGSKeyword* GetDefaultKeyword() const { return nullptr; }  // 07

		void CopyKeywords(const std::vector<RE::BGSKeyword*>& a_copiedData);

		void AddKeyword(BGSKeyword* a_keyword)
		{
			using func_t = decltype(&BGSKeywordForm::AddKeyword);
			static REL::Relocation<func_t> func{ REL::ID(2192766) };
			return func(this, a_keyword);
		}

		bool AddKeywords(const std::vector<BGSKeyword*>& a_keywords);

		[[nodiscard]] bool ContainsKeywordString(std::string_view a_editorID) const;
		[[nodiscard]] bool HasKeywordID(TESFormID a_formID) const;
		[[nodiscard]] bool HasKeywordString(std::string_view a_editorID) const;

		void ForEachKeyword(std::function<BSContainer::ForEachResult(BGSKeyword*)> a_callback) const
		{
			if (keywords) {
				for (std::uint32_t idx = 0; idx < numKeywords; ++idx) {
					if (keywords[idx] && a_callback(keywords[idx]) == BSContainer::ForEachResult::kStop) {
						return;
					}
				}
			}
		}

		[[nodiscard]] std::optional<BGSKeyword*> GetKeywordAt(std::uint32_t a_idx) const
		{
			if (a_idx < numKeywords) {
				return std::make_optional(keywords[a_idx]);
			} else {
				return std::nullopt;
			}
		}

		[[nodiscard]] std::optional<std::uint32_t> GetKeywordIndex(BGSKeyword* a_keyword) const
		{
			if (keywords) {
				for (std::uint32_t i = 0; i < numKeywords; ++i) {
					if (keywords[i] == a_keyword) {
						return i;
					}
				}
			}
			return std::nullopt;
		}

		[[nodiscard]] std::uint32_t GetNumKeywords() const { return numKeywords; };

		void RemoveKeyword(BGSKeyword* a_keyword)
		{
			using func_t = decltype(&BGSKeywordForm::RemoveKeyword);
			static REL::Relocation<func_t> func{ REL::ID(921694) };
			return func(this, a_keyword);
		}

		bool RemoveKeywords(const std::vector<BGSKeyword*>& a_keywords);

		// members
		BGSKeyword**  keywords;     // 10
		std::uint32_t numKeywords;  // 18
	};
	static_assert(sizeof(BGSKeywordForm) == 0x20);

	class __declspec(novtable) BGSMenuDisplayObject :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSMenuDisplayObject };
		static constexpr auto VTABLE{ VTABLE::BGSMenuDisplayObject };

		// members
		TESBoundObject* menuDispObject;  // 08
	};
	static_assert(sizeof(BGSMenuDisplayObject) == 0x10);

	class __declspec(novtable) BGSMessageIcon :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSMessageIcon };
		static constexpr auto VTABLE{ VTABLE::BGSMessageIcon };

		// override (BaseFormComponent)
		void InitializeDataComponent() override;          // 02
		void ClearDataComponent() override;               // 03
		void CopyComponent(BaseFormComponent*) override;  // 06

		[[nodiscard]] const BSFixedString& GetMessageIconTextureName() const noexcept { return icon.textureName; }
		void                               SetMessageIconTextureName(BSFixedString a_texture) { icon.textureName = std::move(a_texture); }

		// members
		TESIcon icon;  // 08
	};
	static_assert(sizeof(BGSMessageIcon) == 0x18);

	class __declspec(novtable) BGSNativeTerminalForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSNativeTerminalForm };
		static constexpr auto VTABLE{ VTABLE::BGSNativeTerminalForm };

		// members
		BGSTerminal* terminal;  // 08
	};
	static_assert(sizeof(BGSNativeTerminalForm) == 0x10);

	class __declspec(novtable) BGSOverridePackCollection :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSOverridePackCollection };
		static constexpr auto VTABLE{ VTABLE::BGSOverridePackCollection };

		// members
		BGSListForm* spectatorOverRidePackList;      // 08
		BGSListForm* observeCorpseOverRidePackList;  // 10
		BGSListForm* guardWarnOverRidePackList;      // 18
		BGSListForm* enterCombatOverRidePackList;    // 20
		BGSListForm* followerCommandPackList;        // 28
		BGSListForm* elevatorOverRidePackList;       // 30
	};
	static_assert(sizeof(BGSOverridePackCollection) == 0x38);

	struct PerkRankData
	{
	public:
		PerkRankData(BGSPerk* a_perk, std::int8_t a_rank) :
			perk(a_perk), currentRank(a_rank)
		{}

		F4_HEAP_REDEFINE_NEW(PerkRankData);

		// members
		BGSPerk*    perk;         // 00
		std::int8_t currentRank;  // 08
	};
	static_assert(sizeof(PerkRankData) == 0x10);

	class __declspec(novtable) BGSPerkRankArray :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSPerkRankArray };
		static constexpr auto VTABLE{ VTABLE::BGSPerkRankArray };

		virtual ~BGSPerkRankArray()  // 00
		{
			ClearPerks(false);
		}

		// override
		virtual void InitializeDataComponent() override;                 // 02
		virtual void ClearDataComponent() override;                      // 03
		virtual void InitComponent() override;                           // 04
		virtual void CopyComponent(BaseFormComponent* a_copy) override;  // 06

		void AllocatePerkRankArray(std::uint32_t a_count)
		{
			using func_t = decltype(&BGSPerkRankArray::AllocatePerkRankArray);
			static REL::Relocation<func_t> func{ REL::ID(888419) };
			return func(this, a_count);
		}

		void ClearPerks(bool a_removeFormUser)
		{
			using func_t = decltype(&BGSPerkRankArray::ClearPerks);
			static REL::Relocation<func_t> func{ REL::ID(1247917) };
			return func(this, a_removeFormUser);
		}

		// members
		PerkRankData* perks;      // 08
		std::uint32_t perkCount;  // 10
	};
	static_assert(sizeof(BGSPerkRankArray) == 0x18);

	class __declspec(novtable) BGSPickupPutdownSounds :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSPickupPutdownSounds };
		static constexpr auto VTABLE{ VTABLE::BGSPickupPutdownSounds };

		// members
		BGSSoundDescriptorForm* pickupSound;   // 08
		BGSSoundDescriptorForm* putdownSound;  // 10
	};
	static_assert(sizeof(BGSPickupPutdownSounds) == 0x18);

	class __declspec(novtable) BGSPreloadable :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSPreloadable };
		static constexpr auto VTABLE{ VTABLE::BGSPreloadable };

		// add
		virtual void QueueModelsImpl(void* a_queued, IO_TASK_PRIORITY, QueuedFile*, const TBO_InstanceData*) = 0;  // 07 - todo
	};
	static_assert(sizeof(BGSPreloadable) == 0x8);

	class __declspec(novtable) BGSPreviewTransform :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSPreviewTransform };
		static constexpr auto VTABLE{ VTABLE::BGSPreviewTransform };

		// override (BaseFormComponent)
		std::uint32_t GetFormComponentType() const override { return 'NRTP'; }     // 01
		void          InitializeDataComponent() override { transform = nullptr; }  // 02
		void          ClearDataComponent() override { return; }                    // 03
		void          InitComponent() override;                                    // 04
		void          CopyComponent(BaseFormComponent*) override { return; }       // 06
		void          CopyComponent(BaseFormComponent*, TESForm*) override;        // 05

		// members
		BGSTransform* transform;  // 08
	};
	static_assert(sizeof(BGSPreviewTransform) == 0x10);

	class __declspec(novtable) BGSPropertySheet :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSPropertySheet };
		static constexpr auto VTABLE{ VTABLE::BGSPropertySheet };

		// members
		BSTArray<BSTTuple<TESForm*, BGSTypedFormValuePair::SharedVal>>* properties;  // 08
	};
	static_assert(sizeof(BGSPropertySheet) == 0x10);

	class __declspec(novtable) BGSSkinForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSkinForm };
		static constexpr auto VTABLE{ VTABLE::BGSSkinForm };

		// members
		TESObjectARMO* formSkin;  // 08
	};
	static_assert(sizeof(BGSSkinForm) == 0x10);

	class __declspec(novtable) BGSSoundTagComponent :
		public BaseFormComponent  // 0
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSoundTagComponent };
		static constexpr auto VTABLE{ VTABLE::BGSSoundTagComponent };

		// override (BaseFormComponent)
		std::uint32_t GetFormComponentType() const override { return 'CTAC'; }  // 01
		void          InitializeDataComponent() override { return; }            // 02
		void          ClearDataComponent() override;                            // 03
		void          InitComponent() override;                                 // 04
		void          CopyComponent(BaseFormComponent*) override { return; }    // 06
		void          CopyComponent(BaseFormComponent*, TESForm*) override;     // 05
	};
	static_assert(sizeof(BGSSoundTagComponent) == 0x8);

	class ContainerItemExtra
	{
	public:
		union Conditional
		{
			Conditional() :
				ownerGlobal(nullptr)
			{}
			~Conditional() = default;

			F4_HEAP_REDEFINE_NEW(Conditional);

			TESGlobal*   ownerGlobal;
			std::int32_t ownerRank;
			void*        u;
		};
		static_assert(sizeof(Conditional) == 0x8);

		ContainerItemExtra() :
			ownerForm(nullptr),
			conditional(),
			healthMult(100.0f)
		{}
		ContainerItemExtra(TESForm* a_owner) :
			ownerForm(a_owner),
			conditional(),
			healthMult(100.0f)
		{}

		F4_HEAP_REDEFINE_NEW(ContainerItemExtra);

		// members
		TESForm*    ownerForm;    // 00
		Conditional conditional;  // 08
		float       healthMult;   // 10
	};
	static_assert(sizeof(ContainerItemExtra) == 0x18);

	class ContainerObject
	{
	public:
		ContainerObject(TESBoundObject* a_obj, std::int32_t a_count) :
			count(a_count),
			obj(a_obj),
			itemExtra()
		{}
		ContainerObject(TESBoundObject* a_obj, std::int32_t a_count, TESForm* a_ownerForm) :
			count(a_count),
			obj(a_obj),
			itemExtra(new ContainerItemExtra(a_ownerForm))
		{}
		~ContainerObject() = default;

		F4_HEAP_REDEFINE_NEW(ContainerObject);

		// members
		std::int32_t        count;      // 00
		TESBoundObject*     obj;        // 08
		ContainerItemExtra* itemExtra;  // 10
	};
	static_assert(sizeof(ContainerObject) == 0x18);

	class __declspec(novtable) TESContainer :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESContainer };
		static constexpr auto VTABLE{ VTABLE::TESContainer };

		void CopyObjectList(const std::vector<ContainerObject*>& a_copiedData)
		{
			const auto oldData = containerObjects;

			const auto newSize = a_copiedData.size();
			const auto newData = calloc<ContainerObject*>(newSize);
			std::ranges::copy(a_copiedData, newData);

			numContainerObjects = static_cast<std::uint32_t>(newSize);
			containerObjects = newData;

			free(oldData);
		}

		void ForEachContainerObject(std::function<bool(ContainerObject&)> a_fn) const
		{
			for (std::uint32_t i = 0; i < numContainerObjects; ++i) {
				auto entry = containerObjects[i];
				if (entry) {
					if (!a_fn(*entry)) {
						break;
					}
				}
			}
		}

		bool AddObject(TESBoundObject* a_object, std::int32_t a_count, TESForm* a_owner)
		{
			bool added = false;
			for (std::uint32_t i = 0; i < numContainerObjects; ++i) {
				if (const auto entry = containerObjects[i]; entry && entry->obj == a_object) {
					entry->count += a_count;
					added = true;
					break;
				}
			}
			if (!added) {
				std::vector<ContainerObject*> copiedData{ containerObjects, containerObjects + numContainerObjects };
				const auto                    newObj = new ContainerObject(a_object, a_count, a_owner);
				copiedData.push_back(newObj);
				CopyObjectList(copiedData);
				return true;
			}
			return added;
		}

		bool AddObjectsToContainer(std::map<TESBoundObject*, std::int32_t>& a_objects, TESForm* a_owner)
		{
			for (std::uint32_t i = 0; i < numContainerObjects; ++i) {
				if (const auto entry = containerObjects[i]; entry && entry->obj) {
					if (auto it = a_objects.find(entry->obj); it != a_objects.end()) {
						entry->count += it->second;
						a_objects.erase(it);
					}
				}
			}
			if (!a_objects.empty()) {
				std::vector<ContainerObject*> copiedData{ containerObjects, containerObjects + numContainerObjects };
				for (auto& [object, count] : a_objects) {
					const auto newObj = new ContainerObject(object, count, a_owner);
					copiedData.push_back(newObj);
				}
				CopyObjectList(copiedData);
			}
			return true;
		}

		// members
		ContainerObject** containerObjects;     // 08
		std::uint32_t     numContainerObjects;  // 10
	};
	static_assert(sizeof(TESContainer) == 0x18);

	struct BGSLocalizedStringDL
	{
	public:
		void GetDescription(BSStringT<char>& a_out, const TESForm* a_form) const
		{
			using func_t = decltype(&BGSLocalizedStringDL::GetDescription);
			static REL::Relocation<func_t> func{ REL::ID(523613) };
			return func(this, a_out, a_form);
		}

		[[nodiscard]] BGSLocalizedStrings::ScrapStringBuffer GetText(TESFile& a_file) const
		{
			using func_t = decltype(&BGSLocalizedStringDL::GetText);
			static REL::Relocation<func_t> func{ REL::ID(472297) };
			return func(this, a_file);
		}

		// members
		std::uint32_t id{ 0 };  // 0
	};
	static_assert(sizeof(BGSLocalizedStringDL) == 0x4);

	class __declspec(novtable) TESDescription :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESDescription };
		static constexpr auto VTABLE{ VTABLE::TESDescription };

		// override (BaseFormComponent)
		void InitializeDataComponent() override  // 02
		{
			fileOffset = 0;
			chunkOffset = 0;
		}

		void ClearDataComponent() override { return; }    // 03
		void CopyComponent(BaseFormComponent*) override;  // 06

		void GetDescription(BSStringT<char>& a_outString, const TESForm* a_form = nullptr)
		{
			using func_t = decltype(&TESDescription::GetDescription);
			static REL::Relocation<func_t> func{ REL::ID(523613) };
			return func(this, a_outString, a_form);
		}

		// members
		std::uint32_t        fileOffset;       // 08
		std::uint32_t        chunkOffset;      // 0C
		BGSLocalizedStringDL descriptionText;  // 10
	};
	static_assert(sizeof(TESDescription) == 0x18);

	class __declspec(novtable) TESEnchantableForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESEnchantableForm };
		static constexpr auto VTABLE{ VTABLE::TESEnchantableForm };

		virtual MagicSystem::CastingType GetCastingType() const { return *castingType; }  // 07

		[[nodiscard]] std::uint16_t    GetBaseCharge() const noexcept { return amountOfEnchantment; }
		[[nodiscard]] EnchantmentItem* GetBaseEnchanting() const noexcept { return formEnchanting; }
		void                           SetBaseCharge(std::uint16_t a_amount) noexcept { amountOfEnchantment = a_amount; }
		void                           SetBaseEnchanting(EnchantmentItem* a_ench) noexcept { formEnchanting = a_ench; }

		// members
		EnchantmentItem*                                      formEnchanting;       // 08
		REX::EnumSet<MagicSystem::CastingType, std::uint16_t> castingType;          // 10
		std::uint16_t                                         amountOfEnchantment;  // 12
	};
	static_assert(sizeof(TESEnchantableForm) == 0x18);

	class __declspec(novtable) TESFullName :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESFullName };
		static constexpr auto VTABLE{ VTABLE::TESFullName };

		// add
		virtual std::uint32_t GetFullNameLength() const { return fullName.length(); }  // 07
		virtual const char*   GetFullName() const { return fullName.c_str(); }         // 08

		[[nodiscard]] static std::string_view GetFullName(const TESForm& a_form, bool a_strict = false);

		[[nodiscard]] static auto GetSparseFullNameMap()
			-> BSTHashMap<const TESForm*, BGSLocalizedString>&
		{
			static REL::Relocation<BSTHashMap<const TESForm*, BGSLocalizedString>*> sparseFullNameMap{ REL::ID(2661402), -0x8 };
			return *sparseFullNameMap;
		}

		static void SetFullName(TESForm& a_form, std::string_view a_fullName);

		// members
		BGSLocalizedString fullName;  // 08
	};
	static_assert(sizeof(TESFullName) == 0x10);

	class __declspec(novtable) TESHealthForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESHealthForm };
		static constexpr auto VTABLE{ VTABLE::TESHealthForm };

		// override (BaseFormComponent)
		void InitializeDataComponent() override;          // 02
		void ClearDataComponent() override;               // 03
		void CopyComponent(BaseFormComponent*) override;  // 06

		[[nodiscard]] static std::uint32_t GetFormHealth(const TESForm* a_form, const TBO_InstanceData* a_data)
		{
			using func_t = decltype(&TESHealthForm::GetFormHealth);
			static REL::Relocation<func_t> func{ REL::ID(2193227) };
			return func(a_form, a_data);
		}

		// members
		std::uint32_t health;  // 08
	};
	static_assert(sizeof(TESHealthForm) == 0x10);

	class __declspec(novtable) TESModel :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESModel };
		static constexpr auto VTABLE{ VTABLE::TESModel };

		// override (BaseFormComponent)
		void InitializeDataComponent() override;          // 02
		void ClearDataComponent() override;               // 03
		void CopyComponent(BaseFormComponent*) override;  // 06

		// add
		virtual const char*           GetModel() const { return model.c_str(); }          // 07
		virtual void                  SetModel(const char* a_model) { model = a_model; }  // 08
		virtual BGSModelMaterialSwap* GetAsModelMaterialSwap() { return nullptr; }        // 09

		// members
		BSFixedString   model;            // 08
		BSResource::ID* textures;         // 10
		BSResource::ID* materials;        // 18
		std::uint32_t*  addons;           // 20
		std::int8_t     numTextures;      // 28
		std::int8_t     numTexturesSRGB;  // 29
		std::int8_t     numAddons;        // 2A
		std::int8_t     numMaterials;     // 2B
		std::int8_t     flags;            // 2C
	};
	static_assert(sizeof(TESModel) == 0x30);

	class __declspec(novtable) BGSBehaviorGraphModel :
		public TESModel  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSBehaviorGraphModel };
		static constexpr auto VTABLE{ VTABLE::BGSBehaviorGraphModel };
	};
	static_assert(sizeof(BGSBehaviorGraphModel) == 0x30);

	class __declspec(novtable) BGSModelMaterialSwap :
		public TESModel  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSModelMaterialSwap };
		static constexpr auto VTABLE{ VTABLE::BGSModelMaterialSwap };

		// members
		BGSMaterialSwap* swapForm;             // 30
		float            colorRemappingIndex;  // 38
	};
	static_assert(sizeof(BGSModelMaterialSwap) == 0x40);

	class __declspec(novtable) BGSTextureModel :
		public TESModel  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSTextureModel };
		static constexpr auto VTABLE{ VTABLE::BGSTextureModel };
	};
	static_assert(sizeof(BGSTextureModel) == 0x30);

	class __declspec(novtable) TESModelRDT :
		public TESModel  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESModelRDT };
		static constexpr auto VTABLE{ VTABLE::TESModelRDT };
	};
	static_assert(sizeof(TESModelRDT) == 0x30);

	struct ACTOR_BASE_DATA
	{
	public:
		enum class Flag
		{
			kNone = 0,
			kFemale = 1 << 0,
			kEssential = 1 << 1,
			kIsChargenFacePreset = 1 << 2,
			kRespawn = 1 << 3,
			kAutoCalcStats = 1 << 4,
			kUnique = 1 << 5,
			kDoesntAffectStealthMeter = 1 << 6,
			kPCLevelMult = 1 << 7,
			kUsesTemplate = 1 << 8,
			kProtected = 1 << 11,
			kSummonable = 1 << 14,
			kDoesntBleed = 1 << 16,
			kBleedoutOverride = 1 << 18,
			kOppositeGenderanims = 1 << 19,
			kSimpleActor = 1 << 20,
			kLoopedScript = 1 << 21,  // ?
			kLoopedAudio = 1 << 28,   // ?
			kIsGhost = 1 << 29,
			kInvulnerable = 1 << 31
		};

		enum class TEMPLATE_USE_FLAG
		{
			kNone = 0,
			kTraits = 1 << 0,
			kStats = 1 << 1,
			kFactions = 1 << 2,
			kSpells = 1 << 3,
			kAIData = 1 << 4,
			kAIPackages = 1 << 5,
			kUnused = 1 << 6,
			kBaseData = 1 << 7,
			kInventory = 1 << 8,
			kScript = 1 << 9,
			kAIDefPackList = 1 << 10,
			kAttackData = 1 << 11,
			kKeywords = 1 << 12
		};

		// members
		REX::EnumSet<Flag, std::uint32_t>              actorBaseFlags;    // 00
		std::int16_t                                   xpValueOffset;     // 04
		std::uint16_t                                  level;             // 06
		std::uint16_t                                  calcLevelMin;      // 08
		std::uint16_t                                  calcLevelMax;      // 0A
		std::uint16_t                                  baseDisposition;   // 0C
		REX::EnumSet<TEMPLATE_USE_FLAG, std::uint16_t> templateUseFlags;  // 0E
		std::int16_t                                   bleedoutOverride;  // 10
	};
	static_assert(sizeof(ACTOR_BASE_DATA) == 0x14);

	struct FACTION_RANK
	{
	public:
		// members
		TESFaction* faction;  // 00
		std::int8_t rank;     // 08
	};
	static_assert(sizeof(FACTION_RANK) == 0x10);

	class __declspec(novtable) TESActorBaseData :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESActorBaseData };
		static constexpr auto VTABLE{ VTABLE::TESActorBaseData };

		// add
		virtual void CopyFromTemplateForms([[maybe_unused]] TESActorBase** a_forceTemplates) { return; }  // 07
		virtual bool GetIsGhost() const;                                                                  // 08
		virtual bool GetInvulnerable() const;                                                             // 09

		[[nodiscard]] constexpr bool AffectsStealthMeter() const noexcept { return actorData.actorBaseFlags.none(ACTOR_BASE_DATA::Flag::kDoesntAffectStealthMeter); }
		[[nodiscard]] constexpr bool Bleeds() const noexcept { return actorData.actorBaseFlags.none(ACTOR_BASE_DATA::Flag::kDoesntBleed); }
		[[nodiscard]] constexpr bool IsEssential() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kEssential); }
		[[nodiscard]] constexpr bool IsFemale() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kFemale); }
		[[nodiscard]] inline bool    IsGhost() const { return GetIsGhost(); }
		[[nodiscard]] constexpr bool IsPreset() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kIsChargenFacePreset); }
		[[nodiscard]] constexpr bool IsProtected() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kProtected); }
		[[nodiscard]] constexpr bool IsSimpleActor() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kSimpleActor); }
		[[nodiscard]] constexpr bool IsSummonable() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kSummonable); }
		[[nodiscard]] constexpr bool IsUnique() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kUnique); }
		[[nodiscard]] inline bool    IsInvulnerable() const { return GetInvulnerable(); }
		[[nodiscard]] constexpr bool HasAutoCalcStats() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kAutoCalcStats); }
		[[nodiscard]] constexpr bool HasBleedoutOverride() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kBleedoutOverride); }
		[[nodiscard]] constexpr bool HasPCLevelMult() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kPCLevelMult); }
		[[nodiscard]] constexpr bool Respawns() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kRespawn); }
		[[nodiscard]] constexpr bool UsesOppositeGenderAnims() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kOppositeGenderanims); }
		[[nodiscard]] constexpr bool UsesTemplate() const noexcept { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flag::kUsesTemplate); }

		std::uint16_t GetLevel() const
		{
			using func_t = decltype(&TESActorBaseData::GetLevel);
			static REL::Relocation<func_t> func{ REL::ID(2192891) };
			return func(this);
		}

		// members
		ACTOR_BASE_DATA        actorData;         // 08
		std::int32_t           changeFlags;       // 1C
		TESLevItem*            deathItem;         // 20
		BGSVoiceType*          voiceType;         // 28
		TESForm*               baseTemplateForm;  // 30
		TESForm**              templateForms;     // 38
		TESGlobal*             legendChance;      // 40
		TESForm*               legendTemplate;    // 48
		BSTArray<FACTION_RANK> factions;          // 50
	};
	static_assert(sizeof(TESActorBaseData) == 0x68);

	struct AIDATA_GAME
	{
	public:
		// members
		std::uint32_t aggression: 2;      // 00:00
		std::uint32_t confidence: 3;      // 00:02
		std::uint32_t energy: 8;          // 00:05
		std::uint32_t morality: 2;        // 00:13
		std::uint32_t unused: 3;          // 00:15
		std::uint32_t assistance: 2;      // 00:18
		std::uint32_t useAggroRadius: 1;  // 00:20
		std::uint16_t aggroRadius[3];     // 04
		std::uint32_t noSlowApproach: 1;  // 0A:00
	};
	static_assert(sizeof(AIDATA_GAME) == 0x10);

	class PackageList
	{
	public:
		// members
		BSSimpleList<TESPackage*> listPackages;
	};
	static_assert(sizeof(PackageList) == 0x10);

	class __declspec(novtable) TESAIForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESAIForm };
		static constexpr auto VTABLE{ VTABLE::TESAIForm };

		// members
		AIDATA_GAME aiData;      // 08
		PackageList aiPackList;  // 18
	};
	static_assert(sizeof(TESAIForm) == 0x28);

	class __declspec(novtable) TESBipedModelForm :
		public BaseFormComponent  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::TESBipedModelForm };
		static constexpr auto VTABLE{ VTABLE::TESBipedModelForm };

		// members
		BGSModelMaterialSwap worldModel[2];       // 008
		TESIcon              inventoryIcon[2];    // 088
		BGSMessageIcon       messageIcon[2];      // 0A8
		TESModelRDT          constraintTemplate;  // 0D8
	};
	static_assert(sizeof(TESBipedModelForm) == 0x108);

	class __declspec(novtable) TESImageSpaceModifiableForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESImageSpaceModifiableForm };
		static constexpr auto VTABLE{ VTABLE::TESImageSpaceModifiableForm };

		// members
		TESImageSpaceModifier* formImageSpaceModifying;  // 08
	};
	static_assert(sizeof(TESImageSpaceModifiableForm) == 0x10);

	struct INSTANCE_FILTER
	{
	public:
		// members
		std::uint32_t                                      levelOverride;     // 00
		std::uint8_t                                       tierStartLevel;    // 04
		std::uint8_t                                       altLevelsPerTier;  // 05
		bool                                               epic;              // 06
		BSScrapArray<BSTTuple<BGSKeyword*, std::uint32_t>> keywordChances;    // 08
	};
	static_assert(sizeof(INSTANCE_FILTER) == 0x28);

	struct CALCED_OBJECT
	{
	public:
		// members
		TESBoundObject*    object;          // 00
		const char*        overrideName;    // 08
		std::int32_t       count;           // 10
		ContainerItemExtra itemExtra;       // 18
		INSTANCE_FILTER    instanceFilter;  // 30
	};
	static_assert(sizeof(CALCED_OBJECT) == 0x58);

	struct LEVELED_OBJECT
	{
	public:
		// members
		TESForm*            form;        // 00
		ContainerItemExtra* itemExtra;   // 08
		std::uint16_t       count;       // 10
		std::uint16_t       level;       // 12
		std::int8_t         chanceNone;  // 14
	};
	static_assert(sizeof(LEVELED_OBJECT) == 0x18);

	class __declspec(novtable) TESLeveledList :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESLeveledList };
		static constexpr auto VTABLE{ VTABLE::TESLeveledList };

		enum class LeveledListAllBelowForce
		{
			kNever = -1,
			kDefault = 0,
			kAlways = 1,
			kShiftUp = 2,
		};

		// add
		virtual std::int8_t  GetChanceNone();                                          // 07
		virtual bool         GetMultCalc();                                            // 08
		virtual std::int32_t GetMaxLevelDifference() { return 0; }                     // 09
		virtual const char*  GetOverrideName() { return nullptr; }                     // 0A
		virtual bool         GetCanContainFormsOfType(ENUM_FORM_ID a_type) const = 0;  // 0B

		LEVELED_OBJECT* AddLeveledObject(std::uint16_t a_level, std::uint16_t a_count, std::int8_t a_chanceNone, TESForm* a_item, ContainerItemExtra* a_itemExtra)
		{
			using func_t = decltype(&TESLeveledList::AddLeveledObject);
			static REL::Relocation<func_t> func{ REL::ID(2193258) };
			return func(this, a_level, a_count, a_chanceNone, a_item, a_itemExtra);
		}

		void CalculateCurrentFormList(
			std::uint16_t                a_level,
			std::uint16_t                a_count,
			BSScrapArray<CALCED_OBJECT>& a_outCont,
			LeveledListAllBelowForce     a_allBelowForce = LeveledListAllBelowForce::kDefault,
			bool                         a_clampToPlayer = false,
			INSTANCE_FILTER*             a_instanceFilter = nullptr,
			const char*                  a_overrideName = nullptr)
		{
			using func_t = decltype(&TESLeveledList::CalculateCurrentFormList);
			static REL::Relocation<func_t> func{ REL::ID(2193259) };
			return func(this, a_level, a_count, a_outCont, a_allBelowForce, a_clampToPlayer, a_instanceFilter, a_overrideName);
		}

		void CalculateCurrentFormListForRef(TESObjectREFR* a_ref, BSScrapArray<CALCED_OBJECT>& a_outCont, bool a_legendary)
		{
			using func_t = decltype(&TESLeveledList::CalculateCurrentFormListForRef);
			static REL::Relocation<func_t> func{ REL::ID(2193260) };
			return func(this, a_ref, a_outCont, a_legendary);
		}

		bool GetUseAll()
		{
			using func_t = decltype(&TESLeveledList::GetUseAll);
			static REL::Relocation<func_t> func{ REL::ID(2193253) };
			return func(this);
		}

		// members
		TESGlobal*                                                      chanceGlobal;      // 08
		BSTArray<BSTTuple<TESForm*, BGSTypedFormValuePair::SharedVal>>* keywordChances;    // 10
		LEVELED_OBJECT*                                                 leveledLists;      // 18
		LEVELED_OBJECT**                                                scriptAddedLists;  // 20
		std::int8_t                                                     scriptListCount;   // 28
		std::int8_t                                                     baseListCount;     // 29
		std::int8_t                                                     chanceNone;        // 2A
		std::int8_t                                                     llFlags;           // 2B
		std::int8_t                                                     maxUseAllCount;    // 2C
	};
	static_assert(sizeof(TESLeveledList) == 0x30);

	class __declspec(novtable) TESModelTri :
		public TESModel  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESModelTri };
		static constexpr auto VTABLE{ VTABLE::TESModelTri };
	};
	static_assert(sizeof(TESModelTri) == 0x30);

	class __declspec(novtable) TESProduceForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESProduceForm };
		static constexpr auto VTABLE{ VTABLE::TESProduceForm };

		// members
		BGSSoundDescriptorForm* harvestSound;      // 08
		TESBoundObject*         produceItem;       // 10
		std::int8_t             produceChance[4];  // 18
	};
	static_assert(sizeof(TESProduceForm) == 0x20);

	class __declspec(novtable) TESRaceForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESRaceForm };
		static constexpr auto VTABLE{ VTABLE::TESRaceForm };

		// add
		virtual bool SwitchRace(TESRace* a_race)  // 07
		{
			formRace = a_race;
			return true;
		}

		[[nodiscard]] TESRace* GetFormRace() const noexcept { return formRace; }
		void                   SetFormRace(TESRace* a_race) noexcept { formRace = a_race; }

		// members
		TESRace* formRace;  // 08
	};
	static_assert(sizeof(TESRaceForm) == 0x10);

	enum class FIGHT_REACTION
	{
		kNeutral = 0x0,
		kEnemy = 0x1,
		kAlly = 0x2,
		kFriend = 0x3
	};

	struct GROUP_REACTION
	{
	public:
		// members
		TESForm*       form;           // 00
		std::int32_t   reaction;       // 08
		FIGHT_REACTION fightReaction;  // 0C
	};
	static_assert(sizeof(GROUP_REACTION) == 0x10);

	class __declspec(novtable) TESReactionForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESReactionForm };
		static constexpr auto VTABLE{ VTABLE::TESReactionForm };

		// members
		BSSimpleList<GROUP_REACTION*> reactionList;   // 08
		std::int8_t                   groupFormType;  // 18
	};
	static_assert(sizeof(TESReactionForm) == 0x20);

	struct __declspec(novtable) TESRegionList :
		public BSSimpleList<TESRegion*>
	{
	public:
		static constexpr auto RTTI{ RTTI::TESRegionList };
		static constexpr auto VTABLE{ VTABLE::TESRegionList };

		virtual ~TESRegionList();  // 00

		// members
		bool          ownsRegionMemory;  // 18
		std::uint8_t  pad19;             // 19
		std::uint16_t pad1A;             // 1A
		std::uint32_t pad1C;             // 1C
	};
	static_assert(sizeof(TESRegionList) == 0x20);

	class __declspec(novtable) TESSpellList :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESSpellList };
		static constexpr auto VTABLE{ VTABLE::TESSpellList };

		struct SpellData
		{
		public:
			SpellData() :
				spells(nullptr),
				levSpells(nullptr),
				shouts(nullptr),
				numSpells(0),
				numLevSpells(0),
				numShouts(0)
			{}
			~SpellData() = default;

			F4_HEAP_REDEFINE_NEW(SpellData);

			void CopySpellList(const std::vector<TESLevSpell*>& a_copiedData)
			{
				const auto oldData = levSpells;

				const auto newSize = a_copiedData.size();
				const auto newData = calloc<TESLevSpell*>(newSize);
				std::ranges::copy(a_copiedData, newData);

				numLevSpells = static_cast<std::uint32_t>(newSize);
				levSpells = newData;

				free(oldData);
			}

			void CopySpellList(const std::vector<SpellItem*>& a_copiedData)
			{
				const auto oldData = spells;

				const auto newSize = a_copiedData.size();
				const auto newData = calloc<SpellItem*>(newSize);
				std::ranges::copy(a_copiedData, newData);

				numSpells = static_cast<std::uint32_t>(newSize);
				spells = newData;

				free(oldData);
			}

			bool AddLevSpells(const std::vector<TESLevSpell*>& a_levSpells)
			{
				std::vector<TESLevSpell*> copiedData{ levSpells, levSpells + numLevSpells };
				std::ranges::remove_copy_if(a_levSpells, std::back_inserter(copiedData), [&](auto& spell) {
					return std::ranges::find(copiedData, spell) != copiedData.end();
				});
				CopySpellList(copiedData);
				return true;
			}

			bool AddSpells(const std::vector<SpellItem*>& a_spells)
			{
				std::vector<SpellItem*> copiedData{ spells, spells + numSpells };
				std::ranges::remove_copy_if(a_spells, std::back_inserter(copiedData), [&](auto& spell) {
					return std::ranges::find(copiedData, spell) != copiedData.end();
				});
				CopySpellList(copiedData);
				return true;
			}

			std::optional<std::uint32_t> GetIndex(const SpellItem* a_spell) const
			{
				if (spells) {
					for (std::uint32_t i = 0; i < numSpells; i++) {
						if (spells[i] == a_spell) {
							return i;
						}
					}
				}
				return std::nullopt;
			}

			std::optional<std::uint32_t> GetIndex(const TESLevSpell* a_levSpell) const
			{
				if (levSpells) {
					for (std::uint32_t i = 0; i < numLevSpells; i++) {
						if (levSpells[i] == a_levSpell) {
							return i;
						}
					}
				}
				return std::nullopt;
			}

			bool RemoveLevSpells(const std::vector<TESLevSpell*>& a_levSpells)
			{
				std::vector<TESLevSpell*> copiedData{ levSpells, levSpells + numLevSpells };
				if (std::erase_if(copiedData, [&](auto& spell) { return std::ranges::find(a_levSpells, spell) != a_levSpells.end(); }) > 0) {
					CopySpellList(copiedData);
					return true;
				}
				return false;
			}

			bool RemoveSpells(const std::vector<SpellItem*>& a_spells)
			{
				std::vector<SpellItem*> copiedData{ spells, spells + numSpells };
				if (std::erase_if(copiedData, [&](auto& spell) { return std::ranges::find(a_spells, spell) != a_spells.end(); }) > 0) {
					CopySpellList(copiedData);
					return true;
				}
				return false;
			}

			// members
			SpellItem**   spells;        // 00
			TESLevSpell** levSpells;     // 08
			TESShout**    shouts;        // 10
			std::uint32_t numSpells;     // 18
			std::uint32_t numLevSpells;  // 1C
			std::uint32_t numShouts;     // 20
		};
		static_assert(sizeof(SpellData) == 0x28);

		bool AddSpell(TESForm* a_spell)
		{
			using func_t = decltype(&TESSpellList::AddSpell);
			static REL::Relocation<func_t> func{ REL::ID(1312083) };
			return func(this, a_spell);
		}

		// members
		SpellData* spellData;  // 08
	};
	static_assert(sizeof(TESSpellList) == 0x10);

	class __declspec(novtable) TESTexture1024 :
		public TESTexture  // 10
	{
	public:
		static constexpr auto RTTI{ RTTI::TESTexture1024 };
		static constexpr auto VTABLE{ VTABLE::TESTexture1024 };

		// override (TESTexture)
		std::uint32_t GetMaxAllowedSize() override { return 1024; }  // 07
	};
	static_assert(sizeof(TESTexture1024) == 0x10);

	class __declspec(novtable) TESValueForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESValueForm };
		static constexpr auto VTABLE{ VTABLE::TESValueForm };

		[[nodiscard]] static std::uint32_t GetFormValue(const TESForm* a_form, const TBO_InstanceData* a_data)
		{
			using func_t = std::int32_t (*)(const TESForm*, const TBO_InstanceData*);
			static REL::Relocation<func_t> func{ REL::ID(885783) };
			return func(a_form, a_data);
		}

		[[nodiscard]] std::int32_t GetFormValue() const noexcept { return value; }
		static void                SetFormValue(TESForm& a_form, std::int32_t a_value);

		// members
		std::int32_t value;  // 08
	};
	static_assert(sizeof(TESValueForm) == 0x10);

	class __declspec(novtable) TESWeightForm :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESWeightForm };
		static constexpr auto VTABLE{ VTABLE::TESWeightForm };

		[[nodiscard]] static float GetFormWeight(const TESForm* a_form, const TBO_InstanceData* a_data)
		{
			using func_t = float (*)(const TESForm*, const TBO_InstanceData*);
			static REL::Relocation<func_t> func{ REL::ID(2193446) };
			return func(a_form, a_data);
		}

		[[nodiscard]] float GetFormWeight() const noexcept { return weight; }
		void                SetFormWeight(float a_weight) noexcept { weight = a_weight; }

		// members
		float weight;  // 08
	};
	static_assert(sizeof(TESWeightForm) == 0x10);
}
