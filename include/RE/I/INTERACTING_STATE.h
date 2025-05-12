#pragma once

namespace RE
{
	enum class INTERACTING_STATE : std::uint32_t
	{
		kNotInteracting = 0x0,
		kWaitingToInteract = 0x1,
		kInteracting = 0x2,
		kWaitingToStopInteracting = 0x3
	};
}
