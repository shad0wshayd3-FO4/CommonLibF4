#pragma once

namespace RE
{
	class TESWeatherList :
		BSSimpleList<WeatherEntry*>
	{
	public:
	};
	static_assert(sizeof(TESWeatherList) == 0x10);
}
