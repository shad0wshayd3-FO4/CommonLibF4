#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSPointerHandle.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/TESObjectREFRs.h"
#include "RE/Bethesda/UserEvents.h"
#include "RE/NetImmerse/NiMatrix3.h"
#include "RE/NetImmerse/NiSmartPointer.h"
#include "RE/Scaleform/GFx/GFx_Player.h"

namespace RE
{
	class bhkNPCollisionObject;
	class BGSMessage;
	class HUDModeType;
	class TESObjectCELL;
	class TESObjectREFR;
	class VATSCommand;

	struct InventoryUserUIInterfaceEntry;

	enum class QuickContainerMode : std::int32_t
	{
		kLoot,
		kTeammate,
		kPowerArmor,
		kTurret,
		kWorkshop,
		kCrafting,
		kStealing,
		kStealingPowerArmor
	};

	namespace ActorEquipManagerEvent
	{
		enum class Type
		{
			Equip = 0,
			Unequip,
		};

		struct Event
		{
			// members
			REX::EnumSet<Type, std::uint16_t> changeType;     // 00
			const BGSObjectInstance*		  itemAffected;   // 08
			Actor*							  actorAffected;  // 10
			std::uint32_t                     stackID;        // 18
		};
		static_assert(sizeof(Event) == 0x20);
	}

	namespace PerkValueEvents
	{
		enum class Type
		{
			Add = 0,
			Remove
		};

		struct PerkValueChangedEvent
		{
			Type changeType;												// 00
			BSPointerHandle<Actor, BSUntypedPointerHandle<21, 5>> owner;	// 04
			BGSPerk* perk;													// 08
			std::uint8_t rank;												// 10
		};
		static_assert(sizeof(PerkValueChangedEvent) == 0x18);

		struct PerkEntryUpdatedEvent
		{
			BSPointerHandle<Actor, BSUntypedPointerHandle<21, 5>> owner;	// 00
			BGSPerkEntry* perkEntry;										// 08
		};
		static_assert(sizeof(PerkEntryUpdatedEvent) == 0x10);
	}

	namespace HolotapeStateChanged
	{
		// intentional
		struct Event
		{};
	}

	namespace BGSInventoryItemEvent
	{
		struct Event
		{
			BSPointerHandle<TESObjectREFR, BSUntypedPointerHandle<21, 5>> owner;	// 00
			InventoryInterface::Handle* item;										// 04
		};
	}

	namespace FavoriteMgr_Events
	{
		struct ComponentFavoriteEvent
		{
			BGSComponent* component;	// 00
			bool isFavorited;
		};
		static_assert(sizeof(ComponentFavoriteEvent) == 0x10);
	}

	namespace PlayerDifficultySettingChanged
	{
		struct Event
		{
			std::uint32_t oldDifficulty;
			std::uint32_t newDifficulty;
		};
		static_assert(sizeof(Event) == 0x8);
	}

	struct BGSActorEvent
	{
	public:
		// member
		ActorHandle actor;  // 00
	};
	static_assert(sizeof(BGSActorEvent) == 0x4);

	struct BGSActorCellEvent : public BGSActorEvent
	{
	public:
		enum class CellFlag
		{
			kEnter = 0,
			kLeave = 1
		};

		// members
		std::uint32_t                         cellID;  // 04
		REX::EnumSet<CellFlag, std::uint32_t> flags;   // 08
	};
	static_assert(sizeof(BGSActorCellEvent) == 0xC);

	struct BGSActorDeathEvent : public BGSActorEvent
	{
	public:
		// members
		ActorHandle attacker;  // 04
		float       damage;    // 08
	};
	static_assert(sizeof(BGSActorDeathEvent) == 0xC);

	struct BSThreadEvent
	{
	public:
		enum class Event
		{
			kOnStartup,
			kOnShutdown
		};

		static void InitSDM()
		{
			using func_t = decltype(&BSThreadEvent::InitSDM);
			static REL::Relocation<func_t> func{ REL::ID(1425097) };
			return func();
		}
	};
	static_assert(std::is_empty_v<BSThreadEvent>);

	struct BSTransformDeltaEvent
	{
	public:
		// members
		NiMatrix3 deltaRotation;
		NiPoint4  deltaTranslation;
		NiPoint4  previousTranslation;
		NiPoint4  previousRotation;
		NiPoint4  previousScale;
		NiPoint4  currentTranslation;
		NiPoint4  currentRotation;
		NiPoint4  currentScale;
	};
	static_assert(sizeof(BSTransformDeltaEvent) == 0xA0);

	struct ApplyColorUpdateEvent
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<ApplyColorUpdateEvent>;

	public:
		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			static REL::Relocation<EventSource_t**> singleton{ REL::ID(421543) };
			if (!*singleton) {
				*singleton = new EventSource_t(&BSTGlobalEvent::GetSingleton()->eventSourceSDMKiller);
			}
			return *singleton;
		}
	};
	static_assert(std::is_empty_v<ApplyColorUpdateEvent>);

	class CanDisplayNextHUDMessage :
		public BSTValueEvent<bool>
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<CanDisplayNextHUDMessage>;

	public:
		CanDisplayNextHUDMessage(bool a_value)
		{
			optionalValue = a_value;
		}

		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			static REL::Relocation<EventSource_t**> singleton{ REL::ID(344866) };
			if (!*singleton) {
				*singleton = new EventSource_t(&BSTGlobalEvent::GetSingleton()->eventSourceSDMKiller);
			}
			return *singleton;
		}
	};

	struct CellAttachDetachEvent
	{
	public:
		enum class EVENT_TYPE
		{
			kPreAttach,
			kPostAttach,
			kPreDetach,
			kPostDetach
		};

		// members
		TESObjectCELL*                         cell;  // 00
		REX::EnumSet<EVENT_TYPE, std::int32_t> type;  // 08
	};
	static_assert(sizeof(CellAttachDetachEvent) == 0x10);

	namespace CellAttachDetachEventSource
	{
		struct CellAttachDetachEventSourceSingleton :
			public BSTSingletonImplicit<CellAttachDetachEventSourceSingleton>
		{
		public:
			[[nodiscard]] static CellAttachDetachEventSourceSingleton& GetSingleton()
			{
				using func_t = decltype(&CellAttachDetachEventSourceSingleton::GetSingleton);
				static REL::Relocation<func_t> func{ REL::ID(862142) };
				return func();
			}

			// members
			BSTEventSource<CellAttachDetachEvent> source;  // 00
		};
		static_assert(sizeof(CellAttachDetachEventSourceSingleton) == 0x58);
	}

	class CurrentRadiationSourceCount :
		public BSTValueEvent<std::uint32_t>
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<CurrentRadiationSourceCount>;

	public:
		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			static REL::Relocation<EventSource_t**> singleton{ REL::ID(2696196) };
			if (!*singleton) {
				*singleton = new EventSource_t(&BSTGlobalEvent::GetSingleton()->eventSourceSDMKiller);
			}
			return *singleton;
		}
	};
	static_assert(sizeof(CurrentRadiationSourceCount) == 0x08);

	struct ColorUpdateEvent
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<ColorUpdateEvent>;

	public:
		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			static REL::Relocation<EventSource_t**> singleton{ REL::ID(1226590) };
			if (!*singleton) {
				*singleton = new EventSource_t(&BSTGlobalEvent::GetSingleton()->eventSourceSDMKiller);
			}
			return *singleton;
		}
	};
	static_assert(std::is_empty_v<ColorUpdateEvent>);

	class CurrentRadsDisplayMagnitude :
		public BSTValueEvent<float>
	{
	public:
	};
	static_assert(sizeof(CurrentRadsDisplayMagnitude) == 0x08);

	class CurrentRadsPercentOfLethal :
		public BSTValueEvent<float>
	{
	public:
	};
	static_assert(sizeof(CurrentRadsPercentOfLethal) == 0x08);

	struct DoBeforeNewOrLoadCompletedEvent
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<DoBeforeNewOrLoadCompletedEvent>;

	public:
		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			static REL::Relocation<EventSource_t**> singleton{ REL::ID(787908) };
			if (!*singleton) {
				*singleton = new EventSource_t(&BSTGlobalEvent::GetSingleton()->eventSourceSDMKiller);
			}
			return *singleton;
		}
	};
	static_assert(sizeof(DoBeforeNewOrLoadCompletedEvent) == 0x01);

	struct HUDModeEvent
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<HUDModeEvent>;

	public:
		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			static REL::Relocation<EventSource_t**> singleton{ REL::ID(683142) };
			if (!*singleton) {
				*singleton = new EventSource_t(&BSTGlobalEvent::GetSingleton()->eventSourceSDMKiller);
			}
			return *singleton;
		}

		// members
		const BSTArray<HUDModeType>* currentHUDModes;
	};
	static_assert(sizeof(HUDModeEvent) == 0x08);

	struct InventoryItemDisplayData
	{
	public:
		InventoryItemDisplayData(
			const ObjectRefHandle                a_inventoryRef,
			const InventoryUserUIInterfaceEntry& a_entry)
		{
			ctor(a_inventoryRef, a_entry);
		}

		void PopulateFlashObject(Scaleform::GFx::Value& a_flashObject)
		{
			a_flashObject.SetMember("text"sv, itemName.c_str());
			a_flashObject.SetMember("count"sv, itemCount);
			a_flashObject.SetMember("equipState"sv, equipState);
			a_flashObject.SetMember("filterFlag"sv, filterFlag);
			a_flashObject.SetMember("isLegendary"sv, isLegendary);
			a_flashObject.SetMember("favorite"sv, isFavorite);
			a_flashObject.SetMember("taggedForSearch"sv, isTaggedForSearch);
			a_flashObject.SetMember("isBetterThanEquippedItem"sv, isBetterThanEquippedItem);
		}

		// members
		BSFixedStringCS itemName;                           // 00
		std::uint32_t   itemCount{ 0 };                     // 08
		std::uint32_t   equipState{ 0 };                    // 0C
		std::uint32_t   filterFlag{ 0 };                    // 10
		bool            isLegendary{ false };               // 14
		bool            isFavorite{ false };                // 15
		bool            isTaggedForSearch{ false };         // 16
		bool            isBetterThanEquippedItem{ false };  // 17

	private:
		InventoryItemDisplayData* ctor(
			const ObjectRefHandle                a_inventoryRef,
			const InventoryUserUIInterfaceEntry& a_entry)
		{
			using func_t = decltype(&InventoryItemDisplayData::ctor);
			static REL::Relocation<func_t> func{ REL::ID(679373) };
			return func(this, a_inventoryRef, a_entry);
		}
	};
	static_assert(sizeof(InventoryItemDisplayData) == 0x18);

	class LocksPicked
	{
	public:
		struct Event
		{
		public:
		};
		static_assert(std::is_empty_v<LocksPicked::Event>);

		[[nodiscard]] static BSTEventSource<LocksPicked::Event>* GetEventSource()
		{
			using func_t = decltype(&LocksPicked::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(594991) };
			return func();
		}
	};
	static_assert(std::is_empty_v<LocksPicked>);

	class MenuModeChangeEvent
	{
	public:
		// members
		BSFixedString menuName;          // 00
		bool          enteringMenuMode;  // 08
	};
	static_assert(sizeof(MenuModeChangeEvent) == 0x10);

	class MenuModeCounterChangedEvent
	{
	public:
		// members
		BSFixedString menuName;      // 00
		bool          incrementing;  // 08
	};
	static_assert(sizeof(MenuModeCounterChangedEvent) == 0x10);

	class MenuOpenCloseEvent
	{
	public:
		// members
		BSFixedString menuName;  // 00
		bool          opening;   // 08
	};
	static_assert(sizeof(MenuOpenCloseEvent) == 0x10);

	class PerkPointIncreaseEvent
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<PerkPointIncreaseEvent>;

	public:
		PerkPointIncreaseEvent(std::uint8_t a_perkCount) :
			perkCount(a_perkCount)
		{}

		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			static REL::Relocation<EventSource_t**> singleton{ REL::ID(685859) };
			if (!*singleton) {
				*singleton = new EventSource_t(&BSTGlobalEvent::GetSingleton()->eventSourceSDMKiller);
			}
			return *singleton;
		}

		// members
		std::uint8_t perkCount{ 0 };  // 00
	};
	static_assert(sizeof(PerkPointIncreaseEvent) == 0x1);

	class PipboyLightEvent :
		public BSTValueEvent<bool>
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<PipboyLightEvent>;

	public:
		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			static REL::Relocation<EventSource_t**> singleton{ REL::ID(2696280) };
			if (!*singleton) {
				*singleton = new EventSource_t(&BSTGlobalEvent::GetSingleton()->eventSourceSDMKiller);
			}
			return *singleton;
		}
	};
	static_assert(sizeof(PipboyLightEvent) == 0x02);

	struct PlayerAmmoCounts
	{
	public:
		// members
		std::uint32_t clipAmmo;     // 00
		std::uint32_t reserveAmmo;  // 04
	};
	static_assert(sizeof(PlayerAmmoCounts) == 0x08);

	class PlayerAmmoCountEvent :
		public BSTValueEvent<PlayerAmmoCounts>
	{
	public:
	};
	static_assert(sizeof(PlayerAmmoCountEvent) == 0x0C);

	class PlayerWeaponReloadEvent :
		public BSTValueEvent<bool>
	{
	public:
	};
	static_assert(sizeof(PlayerWeaponReloadEvent) == 0x02);

	struct PowerArmorLightData
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<PowerArmorLightData>;

	public:
		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			static REL::Relocation<EventSource_t**> singleton{ REL::ID(120809) };
			if (!*singleton) {
				*singleton = new EventSource_t(&BSTGlobalEvent::GetSingleton()->eventSourceSDMKiller);
			}
			return *singleton;
		}

		// members
		bool lightOn;  // 00
	};
	static_assert(sizeof(PowerArmorLightData) == 0x01);

	struct QuickContainerStateData
	{
	public:
		// members
		BSTSmallArray<InventoryItemDisplayData, 5>     itemData;              // 00
		ObjectRefHandle                                containerRef;          // 88
		ObjectRefHandle                                inventoryRef;          // 8C
		BSFixedStringCS                                aButtonText;           // 90
		BSFixedString                                  containerName;         // 98
		BSFixedStringCS                                perkButtonText;        // A0
		std::int32_t                                   selectedClipIndex;     // A8
		REX::EnumSet<QuickContainerMode, std::int32_t> mode;                  // AC
		bool                                           perkButtonEnabled;     // B0
		bool                                           isNewContainer;        // B1
		bool                                           addedDroppedItems;     // B2
		bool                                           isLocked;              // B3
		bool                                           buttonAEnabled;        // B4
		bool                                           buttonXEnabled;        // B5
		bool                                           refreshContainerSize;  // B6
		bool                                           containerActivated;    // B7
	};
	static_assert(sizeof(QuickContainerStateData) == 0xB8);

	class QuickContainerStateEvent :
		public BSTValueEvent<QuickContainerStateData>  // 00
	{
	public:
	};
	static_assert(sizeof(QuickContainerStateEvent) == 0xC0);

	struct HUDPerkVaultBoyData
	{
	public:
		// members
		BSFixedString                 SwfName;
		const BGSSoundDescriptorForm* soundForm;
		bool                          VATSCritAppliedAnim;
		bool                          VATSCritFillenAnim;
		bool                          dialogueSpeechChallengeAnim;
	};
	static_assert(sizeof(HUDPerkVaultBoyData) == 0x18);

	class HUDPerkVaultBoySwfDisplayEvent :
		public BSTValueEvent<HUDPerkVaultBoyData>  // 00
	{
	public:
	};
	static_assert(sizeof(HUDPerkVaultBoySwfDisplayEvent) == 0x20);

	class ShowingDialogueSpeechChallengeAnim :
		public BSTValueEvent<bool>
	{
	public:
	};
	static_assert(sizeof(ShowingDialogueSpeechChallengeAnim) == 0x2);

	namespace SPECIALMenuEvent
	{
		struct NameChangedEvent
		{
		public:
			// members
			const char* fullName;   // 00
			bool        committed;  // 08
		};
		static_assert(sizeof(NameChangedEvent) == 0x10);
	}

	class TerminalHacked
	{
	public:
		struct Event
		{
		public:
			// members
			ObjectRefHandle terminal;  // 00
		};
		static_assert(sizeof(Event) == 0x04);

		[[nodiscard]] static BSTEventSource<TerminalHacked::Event>* GetEventSource()
		{
			using func_t = decltype(&TerminalHacked::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(425579) };
			return func();
		}
	};
	static_assert(std::is_empty_v<TerminalHacked>);

	struct TESActivateEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<TESActivateEvent>* GetEventSource()
		{
			using func_t = decltype(&TESActivateEvent::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(166230) };
			return func();
		}

		// members
		NiPointer<TESObjectREFR> objectActivated;  // 00
		NiPointer<TESObjectREFR> actionRef;        // 08
	};
	static_assert(sizeof(TESActivateEvent) == 0x10);

	struct TESContainerChangedEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<TESContainerChangedEvent>* GetEventSource()
		{
			using func_t = decltype(&TESContainerChangedEvent::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(242538) };
			return func();
		}

		// members
		std::uint32_t oldContainerFormID;  // 00
		std::uint32_t newContainerFormID;  // 04
		std::uint32_t baseObjectFormID;    // 08
		std::int32_t  itemCount;           // 0C
		std::uint32_t referenceFormID;     // 10
		std::uint16_t uniqueID;            // 14
	};
	static_assert(sizeof(TESContainerChangedEvent) == 0x18);

	struct TESDeathEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<TESDeathEvent>* GetEventSource()
		{
			using func_t = decltype(&TESDeathEvent::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(2201833) };
			return func();
		}

		// members
		NiPointer<TESObjectREFR> actorDying;   // 00
		NiPointer<TESObjectREFR> actorKiller;  // 08
		bool                     dead;         // 10
	};
	static_assert(sizeof(TESDeathEvent) == 0x18);

	struct TESEnterSneakingEvent
	{
		[[nodiscard]] static BSTEventSource<TESEnterSneakingEvent>* GetEventSource()
		{
			using func_t = decltype(&TESEnterSneakingEvent::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(2201837) };
			return func();
		}

		// members
		NiPointer<TESObjectREFR> actor;  // 00
	};
	static_assert(sizeof(TESEnterSneakingEvent) == 0x8);

	struct TESEquipEvent
	{
	public:
		// members
		NiPointer<TESObjectREFR> actor;         // 00
		std::uint32_t            baseObject;    // 08
		std::uint32_t            originalRefr;  // 0C
		std::uint16_t            uniqueID;      // 10
		bool                     equipped;      // 12
	};
	static_assert(sizeof(TESEquipEvent) == 0x18);

	struct TESFormDeleteEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<TESFormDeleteEvent>* GetEventSource()
		{
			using func_t = decltype(&TESFormDeleteEvent::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(2201842) };
			return func();
		}

		// members
		TESFormID formID;  // 00
	};
	static_assert(sizeof(TESFormDeleteEvent) == 0x04);

	struct TESFurnitureEvent
	{
	public:
		enum class FurnitureEventType : std::int32_t
		{
			kEnter,
			kExit
		};

		[[nodiscard]] static BSTEventSource<TESFurnitureEvent>* GetEventSource()
		{
			using func_t = decltype(&TESFurnitureEvent::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(2201844) };
			return func();
		}

		[[nodiscard]] constexpr bool IsEnter() const noexcept { return type.all(FurnitureEventType::kEnter); }
		[[nodiscard]] constexpr bool IsExit() const noexcept { return type.all(FurnitureEventType::kExit); }

		// members
		NiPointer<TESObjectREFR>                       actor;            // 00
		NiPointer<TESObjectREFR>                       targetFurniture;  // 08
		REX::EnumSet<FurnitureEventType, std::int32_t> type;             // 10
	};
	static_assert(sizeof(TESFurnitureEvent) == 0x18);

	struct DamageImpactData
	{
	public:
		// members
		NiPoint3A                       location;  // 00
		NiPoint3A                       normal;    // 10
		NiPoint3A                       velocity;  // 20
		NiPointer<bhkNPCollisionObject> colObj;    // 30
	};
	static_assert(sizeof(DamageImpactData) == 0x40);

	class HitData
	{
	public:
		enum class Flag
		{
			kBlocked = 1 << 0,
			kBlockWithWeapon = 1 << 1,
			kBlockCandidate = 1 << 2,
			kCritical = 1 << 3,
			kCriticalOnDeath = 1 << 4,
			kFatal = 1 << 5,
			kDismemberLimb = 1 << 6,
			kExplodeLimb = 1 << 7,
			kCrippleLimb = 1 << 8,
			kDisarm = 1 << 9,
			kDisableWeapon = 1 << 10,
			kSneakAttack = 1 << 11,
			kIgnoreCritical = 1 << 12,
			kPredictDamage = 1 << 13,
			kPredictBaseDamage = 1 << 14,
			kBash = 1 << 15,
			kTimedBash = 1 << 16,
			kPowerAttack = 1 << 17,
			kMeleeAttack = 1 << 18,
			kRicochet = 1 << 19,
			kExplosion = 1 << 20
		};

		// members
		DamageImpactData                                                impactData;              // 00
		ActorHandle                                                     aggressor;               // 40
		ActorHandle                                                     target;                  // 44
		ObjectRefHandle                                                 sourceRef;               // 48
		NiPointer<BGSAttackData>                                        attackData;              // 50
		BGSObjectInstanceT<TESObjectWEAP>                               weapon;                  // 58
		SpellItem*                                                      criticalEffect;          // 68
		SpellItem*                                                      hitEffect;               // 70
		BSTSmartPointer<VATSCommand>                                    VATSCommand;             // 78
		const TESAmmo*                                                  ammo;                    // 80
		BSTArray<BSTTuple<TESForm*, BGSTypedFormValuePair::SharedVal>>* damageTypes;             // 88
		float                                                           healthDamage;            // 90
		float                                                           totalDamage;             // 94
		float                                                           physicalDamage;          // 98
		float                                                           targetedLimbDamage;      // 9C
		float                                                           percentBlocked;          // A0
		float                                                           resistedPhysicalDamage;  // A4
		float                                                           resistedTypedDamage;     // A8
		REX::EnumSet<STAGGER_MAGNITUDE, std::uint32_t>                  stagger;                 // AC
		float                                                           sneakAttackBonus;        // B0
		float                                                           bonusHealthDamageMult;   // B4
		float                                                           pushBack;                // B8
		float                                                           reflectedDamage;         // BC
		float                                                           criticalDamageMult;      // C0
		REX::EnumSet<Flag, std::uint32_t>                               flags;                   // C4
		BGSEquipIndex                                                   equipIndex;              // C8
		std::uint32_t                                                   material;                // D0
		REX::EnumSet<BGSBodyPartDefs::LIMB_ENUM, std::uint32_t>         damageLimb;              // D4
	};
	static_assert(sizeof(HitData) == 0xE0);

	class TESHitEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<TESHitEvent>* GetEventSource()
		{
			using func_t = decltype(&TESHitEvent::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(1411899) };
			return func();
		}

		// members
		HitData                  hitData;           // 000
		NiPointer<TESObjectREFR> target;            // 0E0
		NiPointer<TESObjectREFR> cause;             // 0E8
		BSFixedString            material;          // 0F0
		std::uint32_t            sourceFormID;      // 0F8
		std::uint32_t            projectileFormID;  // 0FC
		bool                     usesHitData;       // 100
	};
	static_assert(sizeof(TESHitEvent) == 0x110);

	struct TESMagicEffectApplyEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<TESMagicEffectApplyEvent>* GetEventSource()
		{
			using func_t = decltype(&TESMagicEffectApplyEvent::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(1327824) };
			return func();
		}

		// members
		NiPointer<TESObjectREFR> target;             // 00
		NiPointer<TESObjectREFR> caster;             // 08
		std::uint32_t            magicEffectFormID;  // 10
	};
	static_assert(sizeof(TESMagicEffectApplyEvent) == 0x18);

	struct TESObjectLoadedEvent
	{
	public:
		[[nodiscard]] static BSTEventSource<TESObjectLoadedEvent>* GetEventSource()
		{
			using func_t = decltype(&TESObjectLoadedEvent::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(2201853) };
			return func();
		}

		// members
		TESFormID formID;  // 00
		bool      loaded;  // 04
	};
	static_assert(sizeof(TESObjectLoadedEvent) == 0x8);

	struct TESSwitchRaceCompleteEvent
	{
		[[nodiscard]] static BSTEventSource<TESSwitchRaceCompleteEvent>* GetEventSource()
		{
			using func_t = decltype(&TESSwitchRaceCompleteEvent::GetEventSource);
			static REL::Relocation<func_t> func{ REL::ID(2201874) };
			return func();
		}

		// members
		NiPointer<TESObjectREFR> actor;  // 00
	};
	static_assert(sizeof(TESSwitchRaceCompleteEvent) == 0x8);

	class TutorialEvent
	{
	public:
		// members
		BSFixedString     eventName;  // 00
		const BGSMessage* assocMsg;   // 08
	};
	static_assert(sizeof(TutorialEvent) == 0x10);

	struct UIAdvanceMenusFunctionCompleteEvent
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<UIAdvanceMenusFunctionCompleteEvent>;

	public:
		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			static REL::Relocation<EventSource_t**> singleton{ REL::ID(1067039) };
			if (!*singleton) {
				*singleton = new EventSource_t(&BSTGlobalEvent::GetSingleton()->eventSourceSDMKiller);
			}
			return *singleton;
		}
	};
	static_assert(std::is_empty_v<UIAdvanceMenusFunctionCompleteEvent>);

	class UserEventEnabledEvent
	{
	public:
		// members
		REX::EnumSet<UserEvents::USER_EVENT_FLAG, std::int32_t> newUserEventFlag;  // 0
		REX::EnumSet<UserEvents::USER_EVENT_FLAG, std::int32_t> oldUserEventFlag;  // 4
		REX::EnumSet<UserEvents::SENDER_ID, std::int32_t>       senderID;          // 8
	};
	static_assert(sizeof(UserEventEnabledEvent) == 0xC);

	struct PositionPlayerEvent
	{
		enum EVENT_TYPE : uint32_t
		{
			PRE_POSITION_PLAYER = 0x0,
			POSITION_PLAYER_PRE_UPDATE_PACKAGES = 0x1,
			POSITION_PLAYER_POST_UPDATE_PACKAGES = 0x2,
			POST_POSITION_PLAYER = 0x3,
			FINISH_POSITION_PLAYER = 0x4,
		};

		// members
		EVENT_TYPE type;
		bool       NoLoadScreen;
	};
	static_assert(sizeof(PositionPlayerEvent) == 0x08);

	class TESInitScriptEvent
	{
	public:
		// Members
		TESObjectREFR* hObjectInitialized;  // 00
	};
	static_assert(sizeof(TESInitScriptEvent) == 0x08);

	class TESInitScriptEventSource : public BSTEventSource<TESInitScriptEvent>
	{
	public:
		[[nodiscard]] static TESInitScriptEventSource* GetSingleton()
		{
			static REL::Relocation<TESInitScriptEventSource*> singleton{ REL::ID(2691330) };
			return singleton.get();
		}
	};
}
