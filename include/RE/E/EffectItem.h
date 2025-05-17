#pragma once

#include "RE/B/BSStringT.h"
#include "RE/E/EffectItemData.h"
#include "RE/T/TESCondition.h"

namespace RE
{
	class EffectItem
	{
	public:
		void GetDescription(BSString* a_buffer, const char* a_beginTagFormat, const char* a_endTagFormat, float a_magnitude, float a_duration)
		{
			using func_t = decltype(&EffectItem::GetDescription);
			static REL::Relocation<func_t> func{ ID::EffectItem::GetDescription };
			return func(this, a_buffer, a_beginTagFormat, a_endTagFormat, a_magnitude, a_duration);
		}

		// members
		EffectItemData data;           // 00
		EffectSetting* effectSetting;  // 10
		float          rawCost;        // 18
		TESCondition   conditions;     // 20
	};
	static_assert(sizeof(EffectItem) == 0x28);
}
