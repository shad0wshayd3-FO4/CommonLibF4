#pragma once

namespace RE
{
	class Modifiers
	{
	public:
		// members
		float modifiers[3];  // 0
	};
	static_assert(sizeof(Modifiers) == 0xC);
}
