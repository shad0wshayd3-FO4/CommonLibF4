#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSSystemFile.h"
#include "RE/B/BSSystemFileStreamer.h"

namespace RE::BSResource
{
	class LooseFileStreamBase
	{
	public:
		static constexpr auto RTTI{ RTTI::BSResource____LooseFileStreamBase };

		[[nodiscard]] std::string_view GetDirName() const { return dirName; }
		[[nodiscard]] std::string_view GetFileName() const { return fileName; }
		[[nodiscard]] std::string_view GetPrefix() const { return prefix; }

		// members
		BSFixedString            prefix;    // 00
		BSFixedString            dirName;   // 08
		BSFixedString            fileName;  // 10
		BSSystemFile             file;      // 18
		BSSystemFileStreamer::ID pathID;    // 28
	};
	static_assert(sizeof(LooseFileStreamBase) == 0x30);
}
