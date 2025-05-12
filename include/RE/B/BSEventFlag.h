#pragma once

namespace RE
{
	class BSEventFlag
	{
	public:
		// members
		void* event{ nullptr };  // 0
	};
	static_assert(sizeof(BSEventFlag) == 0x8);
}
