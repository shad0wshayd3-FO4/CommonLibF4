#pragma once

#include "Scaleform/R/RefCountBase.h"

namespace Scaleform::GFx
{
	class Movie;
	class Value;

	class __declspec(novtable) alignas(0x08) FunctionHandler :
		public RefCountBase<FunctionHandler, 2>  // 00
	{
	public:
		static constexpr auto RTTI{ RE::RTTI::Scaleform__GFx__FunctionHandler };
		static constexpr auto VTABLE{ RE::VTABLE::Scaleform__GFx__FunctionHandler };

		struct Params
		{
		public:
			// members
			Value*        retVal;           // 00
			Movie*        movie;            // 08
			Value*        self;             // 10
			Value*        argsWithThisRef;  // 18
			Value*        args;             // 20
			std::uint32_t argCount;         // 28
			void*         userData;         // 30
		};
		static_assert(sizeof(Params) == 0x38);

		virtual ~FunctionHandler() = default;  // 00

		// add
		virtual void Call(const Params& a_params) = 0;  // 01
	};
	static_assert(sizeof(FunctionHandler) == 0x10);
}
