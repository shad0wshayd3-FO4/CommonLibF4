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

		namespace Internal
		{
			class IFuncCallQuery;
		}

		class __declspec(novtable) IProfilePolicy
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__IProfilePolicy };
			static constexpr auto VTABLE{ VTABLE::BSScript__IProfilePolicy };

			virtual ~IProfilePolicy() = default;  // 00

			// add
			virtual void StackFramePushQueued(std::uint32_t a_stackID, std::uint32_t a_frameNumber, const BSTSmartPointer<Internal::IFuncCallQuery>& a_funcCallQuery) = 0;                                                                 // 01
			virtual void StackFramePushed(std::uint32_t a_stackID, std::uint32_t a_frameNumber, const Variable& a_self, const BSFixedString& a_scriptName, const BSFixedString& a_stateName, const BSFixedString& a_functionName) = 0;     // 02
			virtual void StackFramePopQueued(std::uint32_t a_stackID, std::uint32_t a_frameNumber, const Variable& a_self, const BSFixedString& a_scriptName, const BSFixedString& a_stateName, const BSFixedString& a_functionName) = 0;  // 03
			virtual void StackFramePopped(std::uint32_t a_stackID, std::uint32_t a_frameNumber, const Variable& a_self, const BSFixedString& a_scriptName, const BSFixedString& a_stateName, const BSFixedString& a_functionName) = 0;     // 04
		};
		static_assert(sizeof(IProfilePolicy) == 0x8);
	}
}
