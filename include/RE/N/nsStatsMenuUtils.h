#pragma once

namespace RE
{
	namespace nsStatsMenuUtils
	{
		inline void GetEffectDisplayInfo(MagicItem* a_item, EffectItem* a_effect, float& a_magnitude, float& a_duration)
		{
			using func_t = decltype(&nsStatsMenuUtils::GetEffectDisplayInfo);
			static REL::Relocation<func_t> func{ ID::nsStatsMenuUtils::GetEffectDisplayInfo };
			return func(a_item, a_effect, a_magnitude, a_duration);
		}
	}
}
