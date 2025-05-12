#pragma once

namespace RE
{
	class __declspec(novtable) BSSteamAwardsSystemUtility :
		public BSAwardsSystemUtility  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSSteamAwardsSystemUtility };
		static constexpr auto VTABLE{ VTABLE::BSSteamAwardsSystemUtility };

		virtual ~BSSteamAwardsSystemUtility() {}  // 00
	};
	static_assert(sizeof(BSSteamAwardsSystemUtility) == 0x8);
}
