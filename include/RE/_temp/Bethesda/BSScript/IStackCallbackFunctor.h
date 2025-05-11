#pragma once

#include "RE/Bethesda/BSContainer.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSScript/Variable.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/BSTHashMap.h"
#include "RE/Bethesda/BSTObjectArena.h"
#include "RE/Bethesda/BSTSmartPointer.h"
#include "RE/Bethesda/BSTTuple.h"
#include "RE/Bethesda/MemoryManager.h"

namespace RE
{
	namespace BSScript
	{
		class Variable;

		class __declspec(novtable) alignas(0x08) IStackCallbackFunctor :
			public BSIntrusiveRefCounted
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__IStackCallbackFunctor };
			static constexpr auto VTABLE{ VTABLE::BSScript__IStackCallbackFunctor };

			virtual ~IStackCallbackFunctor();  // 00

			// add
			virtual void CallQueued() = 0;                    // 01
			virtual void CallCanceled() = 0;                  // 02
			virtual void StartMultiDispatch() = 0;            // 03
			virtual void EndMultiDispatch() = 0;              // 04
			virtual void operator()(BSScript::Variable) = 0;  // 05
			virtual bool CanSave() { return false; };         // 06
		};
		static_assert(sizeof(IStackCallbackFunctor) == 0x10);
	}
}
