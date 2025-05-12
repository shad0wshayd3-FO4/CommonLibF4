#pragma once

namespace RE
{
	class __declspec(novtable) BSGFxFunctionBase
	{
	public:
		static constexpr auto RTTI{ RTTI::BSGFxFunctionBase };
		static constexpr auto VTABLE{ VTABLE::BSGFxFunctionBase };

		virtual ~BSGFxFunctionBase();  // 00

		// add
		virtual void CallFlashFunction(const Scaleform::GFx::FunctionHandler::Params&) = 0;

		// members
		Scaleform::Ptr<BSGFxFunctionHandler> handler;   // 08
		BSFixedStringCS                      funcName;  // 10
		UsesBSGFXFunctionHandler*            owner;     // 18
	};
	static_assert(sizeof(BSGFxFunctionBase) == 0x20);
}
