#pragma once

namespace RE
{
	struct TESResponse;

	class ResponseListWrapper
	{
	public:
		// members
		TESResponse* head;  // 0
	};
	static_assert(sizeof(ResponseListWrapper) == 0x8);
}
