#pragma once

namespace RE
{
	struct WeatherEntry
	{
	public:
		// members
		TESWeather* weather;    // 00
		std::uint32_t chance;     // 08
		TESGlobal* chanceVar;  // 10
	};
	static_assert(sizeof(WeatherEntry) == 0x18);
}
