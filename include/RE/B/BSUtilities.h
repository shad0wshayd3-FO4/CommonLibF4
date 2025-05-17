#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	class NiAVObject;

	namespace BSUtilities
	{
		inline std::uint16_t ConvertFloatToHalf(float a_value)
		{
			using func_t = decltype(&ConvertFloatToHalf);
			static REL::Relocation<func_t> func{ ID::BSUtilities::ConvertFloatToHalf };
			return func(a_value);
		}

		inline float ConvertHalfToFloat(std::uint16_t a_value)
		{
			using func_t = decltype(&ConvertHalfToFloat);
			static REL::Relocation<func_t> func{ ID::BSUtilities::ConvertHalfToFloat };
			return func(a_value);
		}

		inline NiAVObject* GetObjectByName(NiAVObject* a_root, const BSFixedString& a_name, bool a_tryInternal, bool a_dontAttach)
		{
			using func_t = decltype(&GetObjectByName);
			static REL::Relocation<func_t> func{ ID::BSUtilities::GetObjectByName };
			return func(a_root, a_name, a_tryInternal, a_dontAttach);
		}
	}
}
