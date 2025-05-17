#pragma once

#include "RE/B/BGSObjectInstance.h"
#include "RE/T/TESObjectWEAP.h"

namespace RE
{
	namespace CombatFormulas
	{
		[[nodiscard]] inline float GetWeaponDisplayAccuracy(const BGSObjectInstanceT<TESObjectWEAP>& a_weapon, Actor* a_actor)
		{
			using func_t = decltype(&CombatFormulas::GetWeaponDisplayAccuracy);
			static REL::Relocation<func_t> func{ ID::CombatFormulas::GetWeaponDisplayAccuracy };
			return func(a_weapon, a_actor);
		}

		[[nodiscard]] inline float GetWeaponDisplayDamage(const BGSObjectInstanceT<TESObjectWEAP>& a_weapon, const TESAmmo* a_ammo, float a_condition)
		{
			using func_t = decltype(&CombatFormulas::GetWeaponDisplayDamage);
			static REL::Relocation<func_t> func{ ID::CombatFormulas::GetWeaponDisplayDamage };
			return func(a_weapon, a_ammo, a_condition);
		}

		[[nodiscard]] inline float GetWeaponDisplayRange(const BGSObjectInstanceT<TESObjectWEAP>& a_weapon)
		{
			using func_t = decltype(&CombatFormulas::GetWeaponDisplayRange);
			static REL::Relocation<func_t> func{ ID::CombatFormulas::GetWeaponDisplayRange };
			return func(a_weapon);
		}

		[[nodiscard]] inline float GetWeaponDisplayRateOfFire(const TESObjectWEAP& a_weapon, const TESObjectWEAP::InstanceData* a_data)
		{
			using func_t = decltype(&CombatFormulas::GetWeaponDisplayRateOfFire);
			static REL::Relocation<func_t> func{ ID::CombatFormulas::GetWeaponDisplayRateOfFire };
			return func(a_weapon, a_data);
		}
	}
}
