#pragma once

namespace RE
{
	class SCRIPT_HEADER
	{
	public:
		// members
		std::uint32_t variableCount;        // 00
		std::uint32_t refObjectCount;       // 04
		std::uint32_t dataSize;             // 08
		std::uint32_t lastID;               // 0C
		bool          isQuestScript;        // 10
		bool          isMagicEffectScript;  // 11
		bool          isCompiled;           // 12
	};
	static_assert(sizeof(SCRIPT_HEADER) == 0x14);
}
