#pragma once

#include "RE/Bethesda/BSContainer.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSScript/IStackCallbackFunctor.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/BSTHashMap.h"
#include "RE/Bethesda/BSTObjectArena.h"
#include "RE/Bethesda/BSTSmartPointer.h"
#include "RE/Bethesda/BSTTuple.h"
#include "RE/Bethesda/MemoryManager.h"

namespace RE
{
	class BSStorage;

	namespace BSScript
	{
		class IStackCallbackFunctor;

		class __declspec(novtable) IStackCallbackSaveInterface
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__IStackCallbackSaveInterface };
			static constexpr auto VTABLE{ VTABLE::BSScript__IStackCallbackSaveInterface };

			virtual ~IStackCallbackSaveInterface();  // 00

			// add
			virtual bool SaveStackCallback(BSStorage& a_buffer, const BSTSmartPointer<IStackCallbackFunctor>& a_callback) const;         // 01
			virtual bool LoadStackCallback(const BSStorage& a_buffer, bool&, BSTSmartPointer<IStackCallbackFunctor>& a_callback) const;  // 02
		};
		static_assert(sizeof(IStackCallbackSaveInterface) == 0x8);
	}
}
