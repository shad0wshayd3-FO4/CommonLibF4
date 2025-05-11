#pragma once

#include "RE/Bethesda/BSContainer.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
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
		class __declspec(novtable) IClientVM
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__IClientVM };
			static constexpr auto VTABLE{ VTABLE::BSScript__IClientVM };

			virtual ~IClientVM();  // 00

			// add
			virtual bool IsVMFrozen() const;  // 01
			virtual void PreSave();           // 02
		};
		static_assert(sizeof(IClientVM) == 0x8);
	}
}
