#pragma once

namespace RE
{
	enum class WEAPON_STATE : std::uint32_t
	{
		kSheathed = 0x0,
		kWantToDraw = 0x1,
		kDrawing = 0x2,
		kDrawn = 0x3,
		kWantToSheathe = 0x4,
		kSheathing = 0x5
	};
}
