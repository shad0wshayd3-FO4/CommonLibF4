#pragma once

#include "RE/Bethesda/BSContainer.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSScript/IVirtualMachine.h"
#include "RE/Bethesda/BSScript/StackFrame.h"
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
		class IVirtualMachine;
		class StackFrame;

		class ISavePatcherInterface
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__ISavePatcherInterface };
			static constexpr auto VTABLE{ VTABLE::BSScript__ISavePatcherInterface };

			virtual ~ISavePatcherInterface() = default;  // 00

			// add
			virtual void PatchStackFrame(StackFrame&, IVirtualMachine&) = 0;  // 01
		};
		static_assert(sizeof(ISavePatcherInterface) == 0x8);
	}
}
