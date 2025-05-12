#pragma once

namespace RE
{
	class NiColor
	{
	public:
		// members
		float r;  // 0
		float g;  // 4
		float b;  // 8
	};
	static_assert(sizeof(NiColor) == 0xC);
}
