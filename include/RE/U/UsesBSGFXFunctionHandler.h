#pragma once

namespace RE
{
	class UsesBSGFXFunctionHandler
	{
	public:
		static constexpr auto RTTI{ RTTI::UsesBSGFXFunctionHandler };

		// members
		BSTArray<msvc::unique_ptr<BSGFxFunctionBase>> functions;  // 00
	};
	static_assert(sizeof(UsesBSGFXFunctionHandler) == 0x18);
}
