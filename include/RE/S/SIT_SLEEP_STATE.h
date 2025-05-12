#pragma once

namespace RE
{
	enum class SIT_SLEEP_STATE : std::uint32_t
	{
		kNormal = 0x0,
		kWantToSit = 0x1,
		kWaitingForSitAnim = 0x2,
		kIsSitting = 0x3,
		kWantToStand = 0x4,
		kWantToSleep = 0x5,
		kWaitingForSleepAnim = 0x6,
		kIsSleeping = 0x7,
		kWantToWake = 0x8
	};
}
