#pragma once

#include "RE/Bethesda/BSContainer.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSScript/ErrorLogger.h"
#include "RE/Bethesda/BSScript/Stack.h"
#include "RE/Bethesda/BSScript/StackFrame.h"
#include "RE/Bethesda/BSScript/TypeInfo.h"
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
		class ErrorLogger;
		class Stack;
		class StackFrame;
		class TypeInfo;

		namespace Internal
		{
			class VirtualMachine;
		}

		class __declspec(novtable) IFunction :
			public BSIntrusiveRefCounted  // 08
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__IFunction };
			static constexpr auto VTABLE{ VTABLE::BSScript__IFunction };

			enum class CallResult
			{
				kCompleted = 0x0,
				kSetupForVM = 0x1,
				kInProgress = 0x2,
				kFailedRetry = 0x3,
				kFailedAbort = 0x4
			};

			enum class FunctionType
			{
				kNormal = 0x0,
				kPropertyGetter = 0x1,
				kPropertySetter = 0x2
			};

			virtual ~IFunction() = default;  // 00

			// add
			virtual const BSFixedString& GetName() const = 0;                                                                                                                        // 01
			virtual const BSFixedString& GetObjectTypeName() const = 0;                                                                                                              // 02
			virtual const BSFixedString& GetStateName() const = 0;                                                                                                                   // 03
			virtual TypeInfo             GetReturnType() const = 0;                                                                                                                  // 04
			virtual std::uint32_t        GetParamCount() const = 0;                                                                                                                  // 05
			virtual void                 GetParam(std::uint32_t a_param, BSFixedString& a_paramName, TypeInfo& a_paramType) const = 0;                                               // 06
			virtual std::uint32_t        GetStackFrameSize() const = 0;                                                                                                              // 07
			virtual bool                 GetIsNative() const = 0;                                                                                                                    // 08
			virtual bool                 GetIsStatic() const = 0;                                                                                                                    // 09
			virtual bool                 GetIsEmpty() const = 0;                                                                                                                     // 0A
			virtual FunctionType         GetFunctionType() const = 0;                                                                                                                // 0B
			virtual std::uint32_t        GetUserFlags() const = 0;                                                                                                                   // 0C
			virtual const BSFixedString& GetDocString() const = 0;                                                                                                                   // 0D
			virtual void                 InsertLocals(StackFrame& a_frame) const = 0;                                                                                                // 0E
			virtual CallResult           Call(const BSTSmartPointer<Stack>& a_stack, ErrorLogger& a_errorLogger, Internal::VirtualMachine& a_vm, bool a_inScriptTasklet) const = 0;  // 0F
			virtual const BSFixedString& GetSourceFilename() const = 0;                                                                                                              // 10
			virtual bool                 TranslateIPToLineNumber(std::uint32_t a_ip, std::uint32_t& a_lineNumber) const = 0;                                                         // 11
			virtual bool                 GetVarNameForStackIndex(std::uint32_t a_index, BSFixedString& a_variableName) const = 0;                                                    // 12
			virtual bool                 CanBeCalledFromTasklets() const = 0;                                                                                                        // 13
			virtual void                 SetCallableFromTasklets(bool a_taskletCallable) = 0;                                                                                        // 14

			F4_HEAP_REDEFINE_NEW(IFunction);
		};
		static_assert(sizeof(IFunction) == 0x10);
	}
}
