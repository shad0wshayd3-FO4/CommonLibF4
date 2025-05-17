#pragma once

#include "RE/I/InventoryUserUIInterface.h"

namespace RE
{
	class __declspec(novtable) BarterMenuTentativeInventoryUIInterface :
		public InventoryUserUIInterface  // 00
	{
	public:
	};
	static_assert(sizeof(BarterMenuTentativeInventoryUIInterface) == 0x80);
}
