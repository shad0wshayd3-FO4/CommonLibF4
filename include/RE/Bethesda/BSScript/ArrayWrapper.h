#pragma once

#include "RE/Bethesda/BSContainer.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSScript/IVirtualMachine.h"
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
		class IVirtualMachine;
		class Variable;

		template <typename T>
		class ArrayWrapper
		{
		public:
			ArrayWrapper() = delete;

			F4_HEAP_REDEFINE_NEW(ArrayWrapper<T>);

		private:
			// members
			Variable wrappedVar;  // 00
		};
		static_assert(sizeof(ArrayWrapper<void*>) == 0x10);

		template <>
		class ArrayWrapper<BSScript::Variable>
		{
		public:
			ArrayWrapper() = delete;
			ArrayWrapper(BSScrapArray<Variable>& a_copy, IVirtualMachine& a_vm)
			{
				ReplaceArray(a_copy, a_vm);
			}

			F4_HEAP_REDEFINE_NEW(ArrayWrapper<BSScript::Variable>);

			void ReplaceArray(BSScrapArray<Variable>& a_copy, IVirtualMachine& a_vm)
			{
				using func_t = decltype(&ArrayWrapper::ReplaceArray);
				static REL::Relocation<func_t> func{ REL::ID(445184) };
				return func(this, a_copy, a_vm);
			}

		private:
			// members
			Variable wrappedVar;  // 00
		};
		static_assert(sizeof(ArrayWrapper<Variable>) == 0x10);
	}
}
