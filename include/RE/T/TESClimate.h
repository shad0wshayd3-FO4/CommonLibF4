#pragma once

#include "RE/T/TESForm.h"
#include "RE/T/TESModel.h"
#include "RE/T/TESTexture.h"
#include "RE/T/TESWeatherList.h"

namespace RE
{
	class __declspec(novtable) TESClimate :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESClimate };
		static constexpr auto VTABLE{ VTABLE::TESClimate };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kCLMT };

		// members
		TESModel       nightSky;       // 20
		TESWeatherList weatherList;    // 50
		TESTexture     skyObjects[2];  // 60
		std::int8_t    data[6];        // 80
	};
	static_assert(sizeof(TESClimate) == 0x88);
}
