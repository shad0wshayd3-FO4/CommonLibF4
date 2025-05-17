#pragma once

namespace RE
{
	class BSStreamHeader
	{
	public:
		// members
		std::uint32_t version;            // 000
		char          author[64];         // 004
		char          processScript[64];  // 044
		char          exportScript[64];   // 084
		char          maxFilePath[260];   // 0C4
	};
	static_assert(sizeof(BSStreamHeader) == 0x1C8);
}
