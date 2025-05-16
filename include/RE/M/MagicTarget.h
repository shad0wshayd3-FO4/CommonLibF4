#pragma once

namespace RE
{
	class ActiveEffectList;

	class __declspec(novtable) MagicTarget
	{
	public:
		static constexpr auto RTTI{ RTTI::MagicTarget };
		static constexpr auto VTABLE{ VTABLE::MagicTarget };

		struct AddTargetData;
		struct SpellDispelData;

		// members
		virtual ~MagicTarget();  // 00

		// add
		virtual bool              AddTarget(AddTargetData& a_data);                                                                                                                              // 01
		virtual TESObjectREFR*    GetTargetStatsObject() { return nullptr; }                                                                                                                     // 02
		virtual bool              MagicTargetIsActor() { return false; }                                                                                                                         // 03
		virtual bool              IsInvulnerable() const { return false; }                                                                                                                       // 04
		virtual void              InvalidateCommandedActorEffect([[maybe_unused]] ActiveEffect* a_effect) { return; }                                                                            // 05
		virtual bool              CanAddActiveEffect() const = 0;                                                                                                                                // 06
		virtual ActiveEffectList* GetActiveEffectList() = 0;                                                                                                                                     // 07
		virtual float             CheckResistance([[maybe_unused]] MagicItem* a_spell, [[maybe_unused]] EffectItem* a_effect, [[maybe_unused]] TESBoundObject* a_source) const { return 1.0F; }  // 08
		virtual void              EffectAdded([[maybe_unused]] ActiveEffect* a_effect) { return; }                                                                                               // 09
		virtual void              EffectRemoved([[maybe_unused]] ActiveEffect* a_effect) { return; }                                                                                             // 0A
		virtual void              EffectActiveStatusChanged([[maybe_unused]] ActiveEffect* a_effect) { return; }                                                                                 // 0B
		virtual bool              CheckAbsorb([[maybe_unused]] Actor* a_caster, [[maybe_unused]] MagicItem* a_spell, [[maybe_unused]] const EffectItem* a_effectItem) { return false; }          // 0C

		[[nodiscard]] bool IsTakingHealthDamageFromActiveEffect()
		{
			using func_t = decltype(&MagicTarget::IsTakingHealthDamageFromActiveEffect);
			static REL::Relocation<func_t> func{ REL::ID(2226397) };
			return func(this);
		}

		[[nodiscard]] bool IsTakingRadDamageFromActiveEffect()
		{
			using func_t = decltype(&MagicTarget::IsTakingRadDamageFromActiveEffect);
			static REL::Relocation<func_t> func{ REL::ID(2226398) };
			return func(this);
		}

		// members
		SpellDispelData* postUpdateDispelList;  // 08
		std::int8_t      flags;                 // 10
	};
	static_assert(sizeof(MagicTarget) == 0x18);
}
