#pragma once

namespace RE
{
	struct GridCell
	{
		// members
		TESObjectCELL* cell;  // 00
	};
	static_assert(sizeof(GridCell) == 0x08);
}
