#pragma once

namespace RE
{
	class PrecomputedNavmeshInfoPathMap :
		public BSPrecomputedNavmeshInfoPathMap  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::PrecomputedNavmeshInfoPathMap };
	};
	static_assert(sizeof(PrecomputedNavmeshInfoPathMap) == 0x48);
}
