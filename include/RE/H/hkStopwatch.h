#pragma once

namespace RE
{
	class hkStopwatch
	{
	public:
		hkStopwatch() = default;

		// members
		std::uint64_t ticksAtStart{ 0 };     // 00
		std::uint64_t ticksTotal{ 0 };       // 08
		std::uint64_t ticksAtSplit{ 0 };     // 10
		std::uint64_t splitTotal{ 0 };       // 18
		hkBool        runningFlag{ false };  // 20
		std::int32_t  numTimings{ 0 };       // 24
		const char* name{ nullptr };       // 28
	};
	static_assert(sizeof(hkStopwatch) == 0x30);
}
