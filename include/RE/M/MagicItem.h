#pragma once

#include "RE/B/BGSKeywordForm.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class __declspec(novtable) MagicItem :
		public TESBoundObject,  // 00
		public TESFullName,     // 68
		public BGSKeywordForm   // 70
	{
	public:
		static constexpr auto RTTI{ RTTI::MagicItem };
		static constexpr auto VTABLE{ VTABLE::MagicItem };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kNONE };

		struct SkillUsageData
		{
		public:
			// members
			EffectItem*     effect;     // 00
			ActorValueInfo* skill;      // 08
			float           magnitude;  // 10
			bool            custom;     // 14
		};
		static_assert(sizeof(SkillUsageData) == 0x18);

		class Data
		{
		public:
			// members
			std::int32_t  costOverride;  // 0
			std::uint32_t flags;         // 4
		};
		static_assert(sizeof(Data) == 0x8);

		// add
		virtual MagicSystem::SpellType   GetSpellType() const = 0;                                                                              // 67
		virtual void                     SetCastingType([[maybe_unused]] MagicSystem::CastingType a_castingType) { return; }                    // 68
		virtual MagicSystem::CastingType GetCastingType() const = 0;                                                                            // 69
		virtual void                     SetDelivery([[maybe_unused]] MagicSystem::Delivery a_delivery) { return; }                             // 6A
		virtual MagicSystem::Delivery    GetDelivery() const = 0;                                                                               // 6B
		virtual bool                     IsValidDelivery(MagicSystem::Delivery) { return true; }                                                // 6C
		virtual float                    GetFixedCastDuration() const { return 0.0F; }                                                          // 6D
		virtual float                    GetRange() const { return 0.0F; }                                                                      // 6E
		virtual bool                     IgnoreResistance() const { return false; }                                                             // 6F
		virtual bool                     IgnoreLOS() const { return false; }                                                                    // 70
		virtual bool                     IsFood() const { return false; }                                                                       // 71
		virtual bool                     GetNoAbsorb() const { return false; }                                                                  // 72
		virtual bool                     GetNoDualCastModifications() const { return false; }                                                   // 73
		virtual bool                     GetSkillUsageData([[maybe_unused]] SkillUsageData& a_data) const { return false; }                     // 74
		virtual bool                     IsPoison() const;                                                                                      // 75
		virtual bool                     IsMedicine() const { return false; }                                                                   // 76
		virtual void                     AdjustCost(float&, Actor*) const { return; }                                                           // 77
		virtual float                    GetChargeTime() const { return 0.0F; }                                                                 // 78
		virtual std::uint32_t            GetMaxEffectCount() const { return 0; }                                                                // 79
		virtual ActorValueInfo*          GetAssociatedSkill() const { return nullptr; }                                                         // 7A
		virtual bool                     IsTwoHanded() const { return false; }                                                                  // 7B
		virtual CHUNK_ID                 GetChunkID() = 0;                                                                                      // 7C
		virtual void                     CopyMagicItemData(MagicItem* a_copy) = 0;                                                              // 7D
		virtual void                     LoadMagicItemChunk([[maybe_unused]] TESFile* a_file, [[maybe_unused]] CHUNK_ID a_chunkID) { return; }  // 7E
		virtual void                     LoadChunkDataPostProcess([[maybe_unused]] TESFile* a_file) { return; }                                 // 7F
		virtual Data*                    GetData() = 0;                                                                                         // 81
		virtual const Data*              GetData() const = 0;                                                                                   // 80
		virtual std::size_t              GetDataSize() const = 0;                                                                               // 82
		virtual void                     InitFromChunk(TESFile* a_file) = 0;                                                                    // 83

		// members
		BSTArray<EffectItem*>                                        listOfEffects;    // 98
		std::int32_t                                                 hostileCount;     // B0
		EffectSetting*                                               avEffectSetting;  // B8
		std::uint32_t                                                preloadCount;     // C0
		BSTSmartPointer<QueuedFile, BSTSmartPointerGamebryoRefCount> preloadedItem;    // C8
	};
	static_assert(sizeof(MagicItem) == 0xD0);
}
