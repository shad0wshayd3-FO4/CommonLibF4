#pragma once

#include "RE/B/BSFixedString.h"
#include "Scaleform/G/GFx_Value.h"

namespace RE
{
	namespace InventoryUserUIUtils
	{
		namespace detail
		{
			inline void AddItemCardInfoEntry(
				Scaleform::GFx::Value& a_array,
				Scaleform::GFx::Value& a_newEntry,
				const BSFixedStringCS& a_textID,
				Scaleform::GFx::Value& a_value,
				float                  a_difference = 0.0F,
				float                  a_totalDamage = FLT_MAX,
				float                  a_compareDamage = FLT_MAX)
			{
				using func_t = decltype(&detail::AddItemCardInfoEntry);
				static REL::Relocation<func_t> func{ REL::ID(2222648) };
				return func(a_array, a_newEntry, a_textID, a_value, a_difference, a_totalDamage, a_compareDamage);
			}
		}

		inline void AddItemCardInfoEntry(Scaleform::GFx::Value& a_array, Scaleform::GFx::Value& a_entry, const char* a_name, Scaleform::GFx::Value a_value, float a_difference, float a_totalValue = FLT_MAX, float a_comparisonValue = FLT_MAX)
		{
			detail::AddItemCardInfoEntry(a_array, a_entry, a_name, a_value, a_difference, a_totalValue, a_comparisonValue);
		}

		inline void AddItemCardInfoEntry(Scaleform::GFx::Value& a_array, Scaleform::GFx::Value& a_entry, const char* a_name = "", Scaleform::GFx::Value a_value = 0)
		{
			detail::AddItemCardInfoEntry(a_array, a_entry, a_name, a_value);
		}

		inline void AddItemCardInfoEntry(Scaleform::GFx::Value& a_array, const char* a_name, Scaleform::GFx::Value a_value)
		{
			Scaleform::GFx::Value entry;
			detail::AddItemCardInfoEntry(a_array, entry, a_name, a_value);
		}
	}
}
