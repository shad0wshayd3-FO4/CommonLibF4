#pragma once

namespace RE
{
	class GridCell
	{
	public:
		// members
		TESObjectCELL* cell;  // 00
	};
	static_assert(sizeof(GridCell) == 0x08);
}
