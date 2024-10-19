#pragma once

#include "REX/W32/NT.h"

namespace RE
{
	struct TLS
	{
		[[nodiscard]] static TLS* GetSingleton()
		{
			return *static_cast<TLS**>(REX::W32::NtCurrentTeb()->threadLocalStoragePointer);
		}

		// members
		std::byte pad000[0x830];  // 000
		bool      consoleMode;    // 830
	};
}
