#pragma once

#include "RE/D/DifficultyLevel.h"
#include "RE/L/LOCK_LEVEL.h"

namespace RE
{
	namespace GamePlayFormulas
	{
		enum class ExperienceActivity : std::int32_t
		{
			kKillNPC = 0x0,
			kHackComputer = 0x1,
		};

		inline bool CanHackGateCheck(LOCK_LEVEL a_lockLevel)
		{
			using func_t = decltype(&GamePlayFormulas::CanHackGateCheck);
			static REL::Relocation<func_t> func{ ID::GamePlayFormulas::CanHackGateCheck };
			return func(a_lockLevel);
		}

		inline bool CanPickLockGateCheck(LOCK_LEVEL a_lockLevel)
		{
			using func_t = decltype(&GamePlayFormulas::CanPickLockGateCheck);
			static REL::Relocation<func_t> func{ ID::GamePlayFormulas::CanPickLockGateCheck };
			return func(a_lockLevel);
		}

		inline float GetExperienceReward(ExperienceActivity a_activity, DifficultyLevel a_difficulty, float a_xpBase)
		{
			using func_t = decltype(&GamePlayFormulas::GetExperienceReward);
			static REL::Relocation<func_t> func{ ID::GamePlayFormulas::GetExperienceReward };
			return func(a_activity, a_difficulty, a_xpBase);
		}

		inline float GetLockXPReward(LOCK_LEVEL a_lockLevel)
		{
			using func_t = decltype(&GamePlayFormulas::GetLockXPReward);
			static REL::Relocation<func_t> func{ ID::GamePlayFormulas::GetLockXPReward };
			return func(a_lockLevel);
		}

		inline float CalculateItemHealthDamageBonus(float a_itemHealth)
		{
			using func_t = decltype(&GamePlayFormulas::CalculateItemHealthDamageBonus);
			static REL::Relocation<func_t> func{ ID::GamePlayFormulas::CalculateItemHealthDamageBonus };
			return func(a_itemHealth);
		}
	}
}
