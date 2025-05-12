#pragma once

namespace RE
{
	struct UniqueNPCData
	{
	public:
		// members
		TESNPC* npc;        // 00
		std::uint32_t refID;      // 08
		BGSLocation* editorLoc;  // 10
	};
	static_assert(sizeof(UniqueNPCData) == 0x18);
}
