#pragma once

#include "RE/B/BSSimpleList.h"

namespace RE
{
	struct WeatherEntry;

	class TESWeatherList :
		BSSimpleList<WeatherEntry*>
	{
	public:
	};
	static_assert(sizeof(TESWeatherList) == 0x10);
}
