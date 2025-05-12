#pragma once

namespace RE
{
	struct SCRIPT_LOCAL
	{
	public:
		// members
		std::uint32_t id;         // 0
		float         value;      // 4
		bool          isInteger;  // 8
	};
	static_assert(sizeof(SCRIPT_LOCAL) == 0xC);
}
