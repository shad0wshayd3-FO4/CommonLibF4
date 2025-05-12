#pragma once

namespace RE
{
	struct Modifiers
	{
	public:
		// members
		float modifiers[3];  // 0
	};
	static_assert(sizeof(Modifiers) == 0xC);
}
