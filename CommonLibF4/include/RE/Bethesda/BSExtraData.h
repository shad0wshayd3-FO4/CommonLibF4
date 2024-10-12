#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSPointerHandle.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTSmartPointer.h"
#include "RE/Bethesda/BSTTuple.h"
#include "RE/Bethesda/FormComponents.h"
#include "RE/Bethesda/MemoryManager.h"
#include "RE/NetImmerse/NiPoint.h"

namespace RE
{
	class BGSObjectInstanceExtra;
	class BSExtraData;
	class ExtraAliasInstanceArray;
	class ExtraCellWaterType;
	class ExtraInstanceData;
	class ExtraLocation;
	class ExtraMaterialSwap;
	class ExtraPowerLinks;
	class ExtraReferenceHandles;
	class ExtraTextDisplayData;
	class ExtraUniqueID;

	enum EXTRA_DATA_TYPE : std::uint32_t
	{
		kNone,  // BSExtraData
		kHavok,
		kCell3D,
		kWaterType,  // ExtraCellWaterType
		kRegionList,
		kSeenData,
		kEditorID,
		kCellMusicType,
		kSkyRegion,
		kCellMidLowProcess,
		kCellDetachTime,
		kPersistentCell,
		kKeywords,
		kAction,
		kStartingPosition,
		kAnim,
		kHavokAnim,
		kBiped,
		kUsedMarkers,
		kDistantData,
		kRagdollData,
		kCellPrevisRefs,
		kInitActions,
		kEssentialProtected,
		kPackagesStartLoc,
		kPackage,
		kTrespassPackage,
		kRunOncePackages,
		kReferenceHandle,  // ExtraReferenceHandles
		kFollower,
		kLevCreaMod,
		kGhost,
		kOriginalReference,
		kOwnership,
		kGlobal,
		kRank,
		kCount,
		kHealth,  // ExtraHealth
		kRangeDistOverride,
		kTimeLeft,
		kCharge,
		kLight,     // ExtraLight
		kLock,      // ExtraLock
		kTeleport,  // ExtraTeleport
		kMapMarker,
		kLeveledCreature,  // ExtraLeveledCreature
		kLevelItem,
		kScale,
		kSeed,
		kMagicCaster,
		kMagicTarget,
		kMasterFileCell,
		kPlayerCrimeList,
		kObjectInstance,  // BGSObjectInstanceExtra
		kEnableStateParent,
		kEnableStateChildren,
		kItemDropper,
		kDroppedItemList,
		kTeleportMarker,
		kInactivePowerArmor,
		kSavedHavokData,
		kCannotWear,
		kPoison,
		kMagicLight,
		kLastFinishedSequence,
		kSavedAnimation,
		kNorthRotation,
		kSpawnCount,
		kFriendHits,
		kHeadTrackTarget,
		kBoundArmor,
		kRefractionProperty,
		kStartingWorldOrCell,  // ExtraStartingWorldOrCell
		kFavorite,             // ExtraFavorite
		kEditorRef3DData,
		kEditorRefMoveData,
		kInfoGeneralTopic,
		kNoRumors,
		kSound,
		kTerminalState,
		kLinkedRef,
		kLinkedRefChildren,
		kActivateRef,
		kActivateRefChildren,
		kTalkToPlayer,
		kObjectHealth,
		kImageSpace,
		kNavmeshPortal,
		kModelSwap,
		kRadius,
		kRadiation,
		kFactionChanges,
		kDismemberedLimbs,
		kActorCause,
		kMultibound,
		kMultiboundData,
		kMultiboundRef,
		kReflectedRefs,
		kReflectorRefs,
		kEmittanceSource,
		kRadioData,
		kCombatStyle,
		kLinkColorPair,
		kPrimitive,
		kOpenCloseActivateRef,
		kAnimNoteReceiver,
		kAmmo,
		kPatrolRefData,
		kPackageData,
		kOcclusionShape,
		kCollisionData,
		kSayOnceADayTopicInfo,
		kEncounterZone,
		kSayToTopicInfo,
		kOcclusionPlaneRefData,
		kPortalRefData,
		kPortal,
		kRoom,
		kGodRays,
		kRoomRefData,
		kGuardedRefData,
		kCreatureAwakeSound,
		kWaterZoneMap,
		kHorse,
		kIgnoredBySandbox,
		kCellAcousticSpace,
		kReservedMarkers,
		kCellTransCount,
		kWaterLightRefs,
		kLitWaterRefs,
		kRadioRepeater,
		kActivateLoopSound,
		kPatrolRefInUseData,
		kAshpileRef,
		kCreatureMovementSound,
		kFollowerSwimBreadcrumbs,
		kAliasInstanceArray,  // ExtraAliasInstanceArray
		kLocation,            // ExtraLocation
		kMasterLocation,
		kLocationRefType,
		kPromotedRef,
		kAnimSequencer,
		kOutfitItem,
		kEditorLocation,
		kLeveledItemBase,
		kLightData,  // ExtraLightData
		kScene,
		kBadPosition,
		kHeadTrackingWeight,
		kFromAlias,
		kShouldWear,
		kFavorCost,
		kAttachArrows3D,
		kTextDisplayData,  // ExtraTextDisplayData
		kAlphaCutoff,
		kEnchantment,
		kSoul,
		kForcedTarget,
		kSoundOutput,
		kUniqueID,  // ExtraUniqueID
		kFlags,
		kRefrPath,
		kDecalGroup,
		kLockList,
		kForcedLandingMarker,
		kLargeRefOwnerCells,
		kCellWaterEnvMap,
		kCellGrassData,
		kTeleportName,
		kActorInteraction,
		kWaterData,
		kWaterCurrentZoneData,
		kAttachRef,
		kAttachRefChildren,
		kGroupConstraint,
		kScriptedAnimDependence,
		kCachedScale,
		kRaceData,
		kGIDBuffer,
		kMissingRefIDs,
		kBendableSplineParams,
		kReferenceGroup,
		kLayer,
		kMovementController,
		kReferenceCharacterController,
		kMaterialSwap,  // ExtraMaterialSwap
		kInstanceData,  // ExtraInstanceData
		kPowerArmor,
		kAcousticParent,
		kInputEnableLayer,
		kProjectedDecalRef,
		kWorkshop,  // Workshop::ExtraData
		kRadioReceiver,
		kCulledBone,
		kActorValueStorage,
		kDirectAtTarget,
		kActivateText,
		kCellCombinedRefs,
		kObjectBreakable,
		kSavedDynamicIdles,
		kIgnoredAttractKeywords,
		kModRank,
		kInteriorLODWorldspace,
		kActorBoneScaleMap,
		kActorFXPickNodes,
		kPowerArmorPreload,
		kAnimGraphPreload,
		kAnimSounds,
		kPowerLinks,  // ExtraPowerLinks
		kSavedUnrecoverableSubgraphs,
		kRefWeaponSounds,
		kRefInvestedGold,
		kRefFurnitureEntryData,
		kVoiceType,

		kTotal
	};

	class BGSAttachParentArray;
	class BGSLocation;
	class BGSMaterialSwap;
	class BGSMessage;
	class BGSRefAlias;
	class TBO_InstanceData;
	class TESActorBase;
	class TESBoundObject;
	class TESForm;
	class TESObjectCELL;
	class TESPackage;
	class TESQuest;
	class TESWaterForm;

	struct INSTANCE_FILTER;
	struct REFR_LOCK;

	namespace BGSMod
	{
		struct ObjectIndexData;

		namespace Attachment
		{
			class Mod;
		}

		namespace Template
		{
			class Item;
		}
	}

	class __declspec(novtable) BSExtraData
	{
	public:
		static constexpr auto RTTI{ RTTI::BSExtraData };
		static constexpr auto VTABLE{ VTABLE::BSExtraData };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kNone };

		BSExtraData() :
			BSExtraData(EXTRA_DATA_TYPE::kNone)
		{}

		BSExtraData(EXTRA_DATA_TYPE a_type) :
			type(a_type)
		{
			stl::emplace_vtable(this);
		}

		virtual ~BSExtraData() = default;  // 00

		// add
		virtual bool CompareImpl([[maybe_unused]] const BSExtraData& a_compare) const { return false; }  // 01
		virtual bool CompareForUI(const BSExtraData* a_compare) const                                    // 02
		{
			if (a_compare && type == a_compare->type) {
				return CompareImpl(*a_compare);
			} else {
				return true;
			}
		}

		F4_HEAP_REDEFINE_NEW(BSExtraData);

		[[nodiscard]] EXTRA_DATA_TYPE GetExtraType() const noexcept { return *type; }

		// members
		BSExtraData*                                next{ nullptr };                 // 08
		std::uint16_t                               flags{ 0 };                      // 10
		REX::EnumSet<EXTRA_DATA_TYPE, std::uint8_t> type{ EXTRA_DATA_TYPE::kNone };  // 12
	};
	static_assert(sizeof(BSExtraData) == 0x18);

	class __declspec(novtable) ExtraCellWaterType :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraCellWaterType };
		static constexpr auto VTABLE{ VTABLE::ExtraCellWaterType };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kWaterType };

		// members
		TESWaterForm* water;  // 18
	};
	static_assert(sizeof(ExtraCellWaterType) == 0x20);

	class __declspec(novtable) ExtraReferenceHandles :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraReferenceHandles };
		static constexpr auto VTABLE{ VTABLE::ExtraReferenceHandles };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kReferenceHandle };

		// members
		ObjectRefHandle originalRef;   // 18
		ObjectRefHandle containerRef;  // 1C
	};
	static_assert(sizeof(ExtraReferenceHandles) == 0x20);

	class __declspec(novtable) ExtraHealth :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraHealth };
		static constexpr auto VTABLE{ VTABLE::ExtraHealth };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kHealth };

		ExtraHealth(float a_health) :
			BSExtraData(TYPE),
			health(a_health)
		{
			stl::emplace_vtable(this);
		}

		// members
		float health;  // 18
	};
	static_assert(sizeof(ExtraHealth) == 0x20);

	class __declspec(novtable) ExtraCharge :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraCharge };
		static constexpr auto VTABLE{ VTABLE::ExtraCharge };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kCharge };

		// members
		float charge;  // 18
	};
	static_assert(sizeof(ExtraCharge) == 0x20);

	struct __declspec(novtable) MapMarkerData :
		public TESFullName  // 00
	{
		enum MARKER_TYPE : std::uint16_t
		{
			kCave = 0x0,
			kCity = 0x1,
			kDiamondCity = 0x2,
			kEncampment = 0x3,
			kIndustrial = 0x4,
			kGovtBuilding = 0x5,
			kMetro = 0x6,
			kMilitaryBase = 0x7,
			kLandmark = 0x8,
			kOffice = 0x9,
			kRuinsTown = 0xA,
			kRuinsUrban = 0xB,
			kSanctuary = 0xC,
			kSettlement = 0xD,
			kSewer = 0xE,
			kVault = 0xF,
			kAirfield = 0x10,
			kBunkerHill = 0x11,
			kCamper = 0x12,
			kCar = 0x13,
			kChurch = 0x14,
			kCountryClub = 0x15,
			kCustomHouse = 0x16,
			kDriveIn = 0x17,
			kElevatedHighway = 0x18,
			kFaneuilHall = 0x19,
			kFarm = 0x1A,
			kFillingStation = 0x1B,
			kForest = 0x1C,
			kGoodNeighbor = 0x1D,
			kGraveyard = 0x1E,
			kHospital = 0x1F,
			kIndustrialDome = 0x20,
			kIndustrialStacks = 0x21,
			kInstitute = 0x22,
			kIrishPride = 0x23,
			kJunkyard = 0x24,
			kObservatory = 0x25,
			kPier = 0x26,
			kPondOrLake = 0x27,
			kQuarry = 0x28,
			kRadioactiveArea = 0x29,
			kRadioTower = 0x2A,
			kSalem = 0x2B,
			kSchool = 0x2C,
			kShipwreck = 0x2D,
			kSubmarine = 0x2E,
			kSwanPond = 0x2F,
			kSynthHead = 0x0,
			kTown = 0x31,
			kBOS = 0x32,
			kBrownstone = 0x33,
			kBunker = 0x34,
			kCastle = 0x35,
			kSkyscraper = 0x36,
			kLibertalia = 0x37,
			kLowrise = 0x38,
			kMinutemen = 0x39,
			kPoliceStation = 0x3A,
			kPrydwen = 0x3B,
			kRailroadFaction = 0x3C,
			kRailroad = 0x3D,
			kSatellite = 0x3E,
			kSentinel = 0x3F,
			kUSSConstitution = 0x40,
			kMechanist = 0x41,
			kRaiderSettlement = 0x42,
			kVassalSettlement = 0x43,
			kPotentialVassalSettlement = 0x44,
			kBottlingPlant = 0x45,
			kGalactic = 0x46,
			kHub = 0x47,
			kKiddieKingdom = 0x48,
			kMonorail = 0x49,
			kRides = 0x4A,
			kSafari = 0x4B,
			kWildWest = 0x4C,
			kPOI = 0x4D,
			kDisciples = 0x4E,
			kOperators = 0x4F,
			kPack = 0x50,
			kDoor = 0x51,
			kCountEditor = 0x52,
			kQuest = 0x53,
			kQuestDoor = 0x54,
			kQuestMultiple = 0x55,
			kPlayerSet = 0x56,
			kPlayerLocation = 0x57,
			kPowerArmorLocation = 0x58,
			kDogmeat = 0x59,
			kTeammate = 0x5A,
			
			kCountTotal = 0x5B
		};

		std::uint8_t flags;				// 10
		std::uint8_t originalFlags;		// 11
		MARKER_TYPE type;               // 12
	};
	static_assert(sizeof(MapMarkerData) == 0x18);

	class __declspec(novtable) ExtraMapMarker :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraMapMarker };
		static constexpr auto VTABLE{ VTABLE::ExtraMapMarker };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kMapMarker };

		// members
		MapMarkerData* mapMarkerData;  // 18
	};
	static_assert(sizeof(ExtraMapMarker) == 0x20);

	class __declspec(novtable) ExtraLock :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraLock };
		static constexpr auto VTABLE{ VTABLE::ExtraLock };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kLock };

		// members
		REFR_LOCK* lock;  // 18
	};
	static_assert(sizeof(ExtraLock) == 0x20);

	class DoorTeleportData
	{
	public:
		// members
		TESObjectCELL*  transitionCell;  // 00
		ObjectRefHandle linkedDoor;      // 08
		NiPoint3        position;        // 0C
		NiPoint3        rotation;        // 18
		std::uint8_t    flags;           // 24
	};
	static_assert(sizeof(DoorTeleportData) == 0x28);

	class __declspec(novtable) ExtraTeleport :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraTeleport };
		static constexpr auto VTABLE{ VTABLE::ExtraTeleport };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kTeleport };

		// members
		DoorTeleportData* teleportData;  // 18
	};
	static_assert(sizeof(ExtraTeleport) == 0x20);

	class __declspec(novtable) ExtraLeveledCreature :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraLeveledCreature };
		static constexpr auto VTABLE{ VTABLE::ExtraLeveledCreature };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kLeveledCreature };

		// members
		TESActorBase* originalBase;   // 18
		TESActorBase* templates[13];  // 20
	};
	static_assert(sizeof(ExtraLeveledCreature) == 0x88);

	class __declspec(novtable) ExtraInstanceData :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraInstanceData };
		static constexpr auto VTABLE{ VTABLE::ExtraInstanceData };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kInstanceData };

		ExtraInstanceData();
		ExtraInstanceData(const TESBoundObject* a_base, BSTSmartPointer<TBO_InstanceData> a_data);

		// members
		const TESBoundObject*             base{ nullptr };  // 18
		BSTSmartPointer<TBO_InstanceData> data;             // 20
	};
	static_assert(sizeof(ExtraInstanceData) == 0x28);

	class __declspec(novtable) BGSObjectInstanceExtra :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSObjectInstanceExtra };
		static constexpr auto VTABLE{ VTABLE::BGSObjectInstanceExtra };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kObjectInstance };

		BGSObjectInstanceExtra() :
			BSExtraData(TYPE)
		{
			stl::emplace_vtable(this);
		}

		BGSObjectInstanceExtra(const BGSMod::Template::Item* a_item, TESForm* a_parentForm, const INSTANCE_FILTER* a_filter)
		{
			ctor(a_item, a_parentForm, a_filter);
		}

		static bool AttachModToReference(TESObjectREFR& a_ref, BGSMod::Attachment::Mod& a_mod, std::uint8_t a_attachIndex, std::uint8_t a_rank)
		{
			using func_t = decltype(&BGSObjectInstanceExtra::AttachModToReference);
			static REL::Relocation<func_t> func{ REL::ID(2189033) };
			return func(a_ref, a_mod, a_attachIndex, a_rank);
		}

		bool HasMod(const BGSMod::Attachment::Mod& a_mod)
		{
			using func_t = decltype(&BGSObjectInstanceExtra::HasMod);
			static REL::Relocation<func_t> func{ REL::ID(2189026) };
			return func(this, a_mod);
		}

		void AddMod(const BGSMod::Attachment::Mod& a_newMod, std::uint8_t a_attachIndex, std::uint8_t a_rank, bool a_removeInvalidMods)
		{
			using func_t = decltype(&BGSObjectInstanceExtra::AddMod);
			static REL::Relocation<func_t> func{ REL::ID(2189025) };
			return func(this, a_newMod, a_attachIndex, a_rank, a_removeInvalidMods);
		}

		void CreateBaseInstanceData(const TESBoundObject& a_object, BSTSmartPointer<TBO_InstanceData>& a_instanceData) const;

		[[nodiscard]] std::span<BGSMod::ObjectIndexData> GetIndexData() const noexcept;

		std::uint32_t RemoveInvalidMods(const BGSAttachParentArray* a_baseObjectParents)
		{
			using func_t = decltype(&BGSObjectInstanceExtra::RemoveInvalidMods);
			static REL::Relocation<func_t> func{ REL::ID(2189028) };
			return func(this, a_baseObjectParents);
		}

		std::uint32_t RemoveMod(const BGSMod::Attachment::Mod* a_mod, std::uint8_t a_attachIndex)
		{
			using func_t = decltype(&BGSObjectInstanceExtra::RemoveMod);
			static REL::Relocation<func_t> func{ REL::ID(2189027) };
			return func(this, a_mod, a_attachIndex);
		}

		// members
		const BSTDataBuffer<1>* values{ nullptr };  // 18
		std::uint16_t           itemIndex{ 0 };     // 20

	private:
		BGSObjectInstanceExtra* ctor(const BGSMod::Template::Item* a_item, TESForm* a_parentForm, const INSTANCE_FILTER* a_filter)
		{
			using func_t = decltype(&BGSObjectInstanceExtra::ctor);
			static REL::Relocation<func_t> func{ REL::ID(1222521) };
			return func(this, a_item, a_parentForm, a_filter);
		}
	};
	static_assert(sizeof(BGSObjectInstanceExtra) == 0x28);

	class __declspec(novtable) ExtraStartingWorldOrCell :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraStartingWorldOrCell };
		static constexpr auto VTABLE{ VTABLE::ExtraStartingWorldOrCell };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kStartingWorldOrCell };

		ExtraStartingWorldOrCell() :
			ExtraStartingWorldOrCell(nullptr)
		{}

		ExtraStartingWorldOrCell(TESForm* a_form) :
			BSExtraData(TYPE),
			startingWorldOrCell(a_form)
		{
			stl::emplace_vtable(this);
		}

		// members
		TESForm* startingWorldOrCell;  // 18
	};
	static_assert(sizeof(ExtraStartingWorldOrCell) == 0x20);

	class __declspec(novtable) ExtraFavorite :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraFavorite };
		static constexpr auto VTABLE{ VTABLE::ExtraFavorite };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kFavorite };

		// members
		std::int8_t quickkeyIndex;  //18
	};
	static_assert(sizeof(ExtraFavorite) == 0x20);

	struct BGSRefAliasInstanceData
	{
	public:
		// members
		TESQuest*              quest;              // 00
		BGSRefAlias*           alias;              // 08
		BSTArray<TESPackage*>* instancedPackages;  // 10
	};
	static_assert(sizeof(BGSRefAliasInstanceData) == 0x18);

	class __declspec(novtable) ExtraAliasInstanceArray :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraAliasInstanceArray };
		static constexpr auto VTABLE{ VTABLE::ExtraAliasInstanceArray };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kAliasInstanceArray };

		// members
		BSTArray<BGSRefAliasInstanceData> aliasArray;      // 18
		BSReadWriteLock                   aliasArrayLock;  // 30
	};
	static_assert(sizeof(ExtraAliasInstanceArray) == 0x38);

	class __declspec(novtable) ExtraLocation :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraLocation };
		static constexpr auto VTABLE{ VTABLE::ExtraLocation };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kLocation };

		// members
		BGSLocation* location;  // 18
	};
	static_assert(sizeof(ExtraLocation) == 0x20);

	class __declspec(novtable) ExtraMaterialSwap :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraMaterialSwap };
		static constexpr auto VTABLE{ VTABLE::ExtraMaterialSwap };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kMaterialSwap };

		ExtraMaterialSwap() :
			BSExtraData(TYPE)
		{
			stl::emplace_vtable(this);
		}

		// members
		BGSMaterialSwap* swap{ nullptr };  // 18
	};
	static_assert(sizeof(ExtraMaterialSwap) == 0x20);

	class __declspec(novtable) ExtraTextDisplayData :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraTextDisplayData };
		static constexpr auto VTABLE{ VTABLE::ExtraTextDisplayData };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kTextDisplayData };

		enum class DisplayDataType
		{
			kUninitialized = -1,
			kCustomName = -2
		};

		[[nodiscard]] const BSFixedStringCS& GetDisplayName(TESBoundObject* a_baseObject)
		{
			using func_t = decltype(&ExtraTextDisplayData::GetDisplayName);
			static REL::Relocation<func_t> func{ REL::ID(1523343) };
			return func(this, a_baseObject);
		}

		// members
		BSFixedStringCS                              displayName;       // 18
		BGSMessage*                                  displayNameText;   // 20
		TESQuest*                                    ownerQuest;        // 28
		REX::EnumSet<DisplayDataType, std::int32_t>  ownerInstance;     // 30
		BSTArray<BSTTuple<BSFixedString, TESForm*>>* textPairs;         // 38
		std::uint16_t                                customNameLength;  // 40
	};
	static_assert(sizeof(ExtraTextDisplayData) == 0x48);

	class __declspec(novtable) ExtraUniqueID :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraUniqueID };
		static constexpr auto VTABLE{ VTABLE::ExtraUniqueID };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kUniqueID };

		// members
		std::uint16_t uniqueID;  // 18
		std::uint32_t baseID;    // 1C
	};
	static_assert(sizeof(ExtraUniqueID) == 0x20);

	class __declspec(novtable) ExtraPowerLinks :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraPowerLinks };
		static constexpr auto VTABLE{ VTABLE::ExtraPowerLinks };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kPowerLinks };

		struct Element
		{
		public:
			// members
			TESFormID     formID;    // 0
			std::uint32_t linkType;  // 4
		};
		static_assert(sizeof(Element) == 0x8);

		// members
		BSTArray<Element> powerLinks;  // 18
	};
	static_assert(sizeof(ExtraPowerLinks) == 0x30);

	class __declspec(novtable) ExtraBendableSplineParams :
		public BSExtraData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ExtraBendableSplineParams };
		static constexpr auto VTABLE{ VTABLE::ExtraBendableSplineParams };
		static constexpr auto TYPE{ EXTRA_DATA_TYPE::kBendableSplineParams };

		struct ParamData_Untilv13
		{
			// members
			float    slack;        // 00
			float    thickness;    // 04
			NiPoint3 halfExtents;  // 08
		};
		static_assert(sizeof(ParamData_Untilv13) == 0x14);

		struct ParamData : public ParamData_Untilv13
		{
			// members
			bool endDetached;  // 14
		};
		static_assert(sizeof(ParamData) == 0x18);

		// members
		ParamData data;  // 18
	};
	static_assert(sizeof(ExtraBendableSplineParams) == 0x30);

	class BaseExtraList
	{
	public:
		void AddExtra(BSExtraData* a_extra)
		{
			assert(a_extra != nullptr);
			assert(a_extra->next == nullptr);

			const auto type = a_extra->GetExtraType();
			assert(!HasType(type));

			if (!_head || !IsHighUseExtra(type)) {
				assert(_tail != nullptr);
				*_tail = a_extra;
				_tail = std::addressof(a_extra->next);
			} else {
				a_extra->next = _head;
				_head = a_extra;
			}

			MarkType(type, true);
		}

		[[nodiscard]] BSExtraData* GetByType(EXTRA_DATA_TYPE a_type) const noexcept
		{
			if (HasType(a_type)) {
				for (auto iter = _head; iter; iter = iter->next) {
					if (iter->GetExtraType() == a_type) {
						return iter;
					}
				}
			}

			return nullptr;
		}

		[[nodiscard]] bool HasType(EXTRA_DATA_TYPE a_type) const noexcept
		{
			assert(a_type < EXTRA_DATA_TYPE::kTotal);
			const auto idx = std::to_underlying(a_type) / 8;
			const auto flags = GetFlags();
			if (!flags.empty() && idx < flags.size()) {
				const auto pos = static_cast<std::uint8_t>(1u << (std::to_underlying(a_type) % 8));
				return (flags[idx] & pos) != 0;
			} else {
				return false;
			}
		}

		std::unique_ptr<BSExtraData> RemoveExtra(EXTRA_DATA_TYPE a_type)
		{
			if (HasType(a_type)) {
				BSExtraData* prev = nullptr;
				for (auto iter = _head; iter; prev = iter, iter = iter->next) {
					if (iter->GetExtraType() == a_type) {
						if (prev) {
							prev->next = iter->next;
						} else {
							_head = iter->next;
						}

						if (!_tail || *_tail == iter) {
							_tail = std::addressof(prev ? prev->next : _head);
						}

						MarkType(a_type, false);
						return std::unique_ptr<BSExtraData>{ iter };
					}
				}
			}

			return nullptr;
		}

	private:
		static constexpr std::size_t N = (std::to_underlying(EXTRA_DATA_TYPE::kTotal) / 8) + 1;

		[[nodiscard]] static bool IsHighUseExtra(EXTRA_DATA_TYPE a_type) noexcept
		{
			return !((std::to_underlying(a_type) - 11) & ~0x22u) && a_type != EXTRA_DATA_TYPE::kLeveledCreature;
		}

		void CreateFlags() { _flags = calloc<std::uint8_t>(N); }

		[[nodiscard]] std::span<std::uint8_t> GetFlags() const noexcept
		{
			if (_flags) {
				return { _flags, N };
			} else {
				return {};
			}
		}

		[[nodiscard]] std::span<std::uint8_t, N> GetOrCreateFlags()
		{
			if (!_flags) {
				CreateFlags();
			}

			return std::span{ reinterpret_cast<std::uint8_t(&)[N]>(*_flags) };
		}

		void MarkType(EXTRA_DATA_TYPE a_type, bool a_set)
		{
			assert(a_type < EXTRA_DATA_TYPE::kTotal);
			const auto idx = std::to_underlying(a_type) / 8;
			const auto pos = static_cast<std::uint8_t>(1u << (std::to_underlying(a_type) % 8));
			const auto flags = GetOrCreateFlags();
			if (a_set) {
				flags[idx] |= pos;
			} else {
				flags[idx] &= ~pos;
			}
		}

		// members
		BSExtraData*  _head{ nullptr };                // 00
		BSExtraData** _tail{ std::addressof(_head) };  // 08
		std::uint8_t* _flags{ nullptr };               // 10
	};
	static_assert(sizeof(BaseExtraList) == 0x18);

	namespace detail
	{
		template <class T>
		concept ExtraDataListConstraint =
			std::derived_from<T, BSExtraData> &&
			!std::is_pointer_v<T> &&
			!std::is_reference_v<T>;
	}

	namespace ComparisonQualifiers
	{
		static bool ContainerQualifier(const BSExtraData* a_extraData)
		{
			using func_t = decltype(ComparisonQualifiers::ContainerQualifier);
			REL::Relocation<func_t> func{ REL::ID(2190674) };
			return func(a_extraData);
		}

		static bool UIQualifier(const BSExtraData* a_extraData)
		{
			using func_t = decltype(ComparisonQualifiers::UIQualifier);
			REL::Relocation<func_t> func{ REL::ID(2190675) };
			return func(a_extraData);
		}
	};

	class ExtraDataList :
		public BSIntrusiveRefCounted  // 00
	{
	public:
		F4_HEAP_REDEFINE_NEW(ExtraDataList);

		void AddExtra(BSExtraData* a_extra)
		{
			const BSAutoWriteLock l{ extraRWLock };
			extraData.AddExtra(a_extra);
		}

		stl::observer<TBO_InstanceData*> CreateInstanceData(TESBoundObject* a_object, bool a_generateName)
		{
			using func_t = decltype(&ExtraDataList::CreateInstanceData);
			static REL::Relocation<func_t> func{ REL::ID(2190185) };
			return func(this, a_object, a_generateName);
		}

		[[nodiscard]] BSExtraData* GetByType(EXTRA_DATA_TYPE a_type) const noexcept
		{
			const BSAutoReadLock l{ extraRWLock };
			return extraData.GetByType(a_type);
		}

		template <detail::ExtraDataListConstraint T>
		[[nodiscard]] T* GetByType() const noexcept
		{
			return static_cast<T*>(GetByType(T::TYPE));
		}

		[[nodiscard]] BGSMod::Attachment::Mod* GetLegendaryMod()
		{
			using func_t = decltype(&ExtraDataList::GetLegendaryMod);
			static REL::Relocation<func_t> func{ REL::ID(2190180) };
			return func(this);
		}

		[[nodiscard]] bool HasType(EXTRA_DATA_TYPE a_type) const noexcept
		{
			const BSAutoReadLock l{ extraRWLock };
			return extraData.HasType(a_type);
		}

		template <detail::ExtraDataListConstraint T>
		[[nodiscard]] bool HasType() const noexcept
		{
			return HasType(T::TYPE);
		}

		std::unique_ptr<BSExtraData> RemoveExtra(EXTRA_DATA_TYPE a_type)
		{
			const BSAutoWriteLock l{ extraRWLock };
			return extraData.RemoveExtra(a_type);
		}

		template <detail::ExtraDataListConstraint T>
		std::unique_ptr<T> RemoveExtra()
		{
			return std::unique_ptr<T>{ static_cast<T*>(RemoveExtra(T::TYPE).release()) };
		}

		bool SetBendableSplineInfo(float* a_thickness, float* a_slack, NiPoint3* a_halfExtents = nullptr, bool* a_detachedEnd = nullptr)
		{
			using func_t = decltype(&ExtraDataList::SetBendableSplineInfo);
			static REL::Relocation<func_t> func{ REL::ID(2190623) };
			return func(this, a_thickness, a_slack, a_halfExtents, a_detachedEnd);
		}

		void SetDisplayNameFromInstanceData(BGSObjectInstanceExtra* a_instExtra, TESBoundObject* a_object, const BSTSmartPointer<TBO_InstanceData>& a_data)
		{
			using func_t = decltype(&ExtraDataList::SetDisplayNameFromInstanceData);
			static REL::Relocation<func_t> func{ REL::ID(2190179) };
			return func(this, a_instExtra, a_object, a_data);
		}

		void SetOverrideName(const char* a_name)
		{
			using func_t = decltype(&ExtraDataList::SetOverrideName);
			static REL::Relocation<func_t> func{ REL::ID(2190167) };
			return func(this, a_name);
		}

		void SetStartingWorldOrCell(TESForm* a_form)
		{
			using func_t = decltype(&ExtraDataList::SetStartingWorldOrCell);
			static REL::Relocation<func_t> func{ REL::ID(2191213) };
			return func(this, a_form);
		}

		float GetHealthPerc()
		{
			using func_t = decltype(&ExtraDataList::GetHealthPerc);
			static REL::Relocation<func_t> func{ REL::ID(2190226) };
			return func(this);
		}

		void SetHealthPerc(float a_healthPerc)
		{
			using func_t = decltype(&ExtraDataList::SetHealthPerc);
			static REL::Relocation<func_t> func{ REL::ID(2190124) };
			return func(this, a_healthPerc);
		}

		bool ClearFavorite()
		{
			using func_t = decltype(&ExtraDataList::ClearFavorite);
			static REL::Relocation<func_t> func{ REL::ID(2190191) };
			return func(this);
		}

		bool IsFavorite()
		{
			using func_t = decltype(&ExtraDataList::IsFavorite);
			static REL::Relocation<func_t> func{ REL::ID(2190189) };
			return func(this);
		}

		bool IsDamaged()
		{
			using func_t = decltype(&ExtraDataList::IsDamaged);
			static REL::Relocation<func_t> func{ REL::ID(2190224) };
			return func(this);
		}

		typedef bool (*ComparisonQualifier)(const BSExtraData*);
		bool CompareList(const ExtraDataList* a_compare, ComparisonQualifier a_qualifier)
		{
			using func_t = decltype(&ExtraDataList::CompareList);
			REL::Relocation<func_t> func{ REL::ID(2190098) };
			return func(this, a_compare, a_qualifier);
		}

		// members
		BaseExtraList           extraData;    // 08
		mutable BSReadWriteLock extraRWLock;  // 20	
	};
	static_assert(sizeof(ExtraDataList) == 0x28);
}
