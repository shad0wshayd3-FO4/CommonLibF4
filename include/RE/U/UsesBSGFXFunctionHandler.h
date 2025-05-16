#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSGFxFunctionBase.h"

namespace RE
{
	class UsesBSGFXFunctionHandler
	{
	public:
		static constexpr auto RTTI{ RTTI::UsesBSGFXFunctionHandler };

		// members
		BSTArray<std::unique_ptr<BSGFxFunctionBase>> functions;  // 00
	};
	static_assert(sizeof(UsesBSGFXFunctionHandler) == 0x18);
}
