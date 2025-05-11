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
		class __declspec(novtable) ICachedErrorMessage
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__ICachedErrorMessage };
			static constexpr auto VTABLE{ VTABLE::BSScript__ICachedErrorMessage };

			virtual ~ICachedErrorMessage() = default;  // 00

			// add
			virtual void GetErrorMsg(BSFixedString& a_message) const = 0;  // 01
		};
		static_assert(sizeof(ICachedErrorMessage) == 0x8);
	}
}
