#pragma once

namespace RE
{
	class EffectItem
	{
	public:
		void GetDescription(BSStringT<char>* a_buffer, const char* a_beginTagFormat, const char* a_endTagFormat, float a_magnitude, float a_duration)
		{
			using func_t = decltype(&EffectItem::GetDescription);
			static REL::Relocation<func_t> func{ REL::ID(2189612) };
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
