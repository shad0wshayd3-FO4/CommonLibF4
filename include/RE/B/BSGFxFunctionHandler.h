#pragma once

#include "RE/G/GFxPlayer.h"

namespace RE
{
	class __declspec(novtable) BSGFxFunctionHandler :
		public Scaleform::GFx::FunctionHandler  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSGFxFunctionHandler };
		static constexpr auto VTABLE{ VTABLE::BSGFxFunctionHandler };

		virtual ~BSGFxFunctionHandler();  // 00

		// override
		virtual void Call(const Scaleform::GFx::FunctionHandler::Params&) override;  // 01

		// members
		Scaleform::GFx::Value flashTarget;                 // 10
		Scaleform::GFx::Value originalFunctionDefinition;  // 30
		BSFixedStringCS       funcName;                    // 50
		BSGFxFunctionBase*    owner;                       // 58
	};
	static_assert(sizeof(BSGFxFunctionHandler) == 0x60);
}
