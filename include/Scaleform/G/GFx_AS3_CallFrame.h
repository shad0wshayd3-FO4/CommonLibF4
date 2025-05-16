#pragma once

#include "Scaleform/G/GFx_AS3_Abc_MbiInd.h"
#include "Scaleform/G/GFx_AS3_Value.h"
#include "Scaleform/N/NewOverrideBase.h"

namespace Scaleform
{
	class MemoryHeap;

	namespace GFx::AS3
	{
		class Traits;
		class ValueRegisterFile;
		class VMAbcFile;

		class __declspec(novtable) CallFrame :
			public NewOverrideBase<330>
		{
		public:
			// members
			bool                 discardResult;        // 00
			bool                 aCopy;                // 01
			std::uint64_t        scopeStackBaseInd;    // 08
			const std::uint64_t* cp;                   // 10
			ValueRegisterFile*   registerValue;        // 18
			MemoryHeap*          heap;                 // 20
			VMAbcFile*           file;                 // 28
			Abc::MbiInd          mbiIndex;             // 30
			const void*          savedScope;           // 38 - TODO
			const Traits*        originationTraits;    // 40
			void*                scopeStack;           // 48 - TODO
			AS3::Value*          prevInitialStackPos;  // 50
			void*                defXMLNamespace;      // 58 - TODO
			AS3::Value*          prevFirstStackPos;    // 60
			AS3::Value           invoker;              // 68
		};
		static_assert(sizeof(CallFrame) == 0x88);
	}
}
