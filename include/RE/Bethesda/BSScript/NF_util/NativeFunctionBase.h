#pragma once

#include "RE/Bethesda/BSContainer.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSScript/ErrorLogger.h"
#include "RE/Bethesda/BSScript/IFunction.h"
#include "RE/Bethesda/BSScript/Internal/VDescTable.h"
#include "RE/Bethesda/BSScript/Stack.h"
#include "RE/Bethesda/BSScript/StackFrame.h"
#include "RE/Bethesda/BSScript/TypeInfo.h"
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
		class ErrorLogger;
		class IFunction;
		class Stack;
		class StackFrame;
		class TypeInfo;
		class Variable;

		namespace NF_util
		{
			class __declspec(novtable) NativeFunctionBase :
				public IFunction  // 00
			{
			public:
				static constexpr auto RTTI{ RTTI::BSScript__NF_util__NativeFunctionBase };
				static constexpr auto VTABLE{ VTABLE::BSScript__NF_util__NativeFunctionBase };

				NativeFunctionBase(
					std::string_view a_object,
					std::string_view a_function,
					std::uint16_t    a_paramCount,
					bool             a_isStatic,
					bool             a_isLatent) :
					name(a_function),
					objName(a_object),
					descTable(a_paramCount, 0),
					isStatic(a_isStatic),
					isLatent(a_isLatent)
				{
					for (std::size_t i = 0; i < descTable.paramCount; ++i) {
						descTable.entries[i].first = std::format("param{}", i + 1);
					}
				}

				// override (IFunction)
				const BSFixedString& GetName() const override { return name; }                          // 01
				const BSFixedString& GetObjectTypeName() const override { return objName; }             // 02
				const BSFixedString& GetStateName() const override { return stateName; }                // 03
				TypeInfo             GetReturnType() const override { return retType; }                 // 04
				std::uint32_t        GetParamCount() const override { return descTable.totalEntries; }  // 05

				void GetParam(std::uint32_t a_param, BSFixedString& a_paramName, TypeInfo& a_paramType) const override  // 06
				{
					if (a_param < descTable.paramCount) {
						assert(descTable.entries != nullptr);
						const auto& entry = descTable.entries[a_param];
						a_paramName = entry.first;
						a_paramType = entry.second;
					} else {
						a_paramName = ""sv;
						a_paramType = nullptr;
					}
				}

				std::uint32_t        GetStackFrameSize() const override { return descTable.totalEntries; }  // 07
				bool                 GetIsNative() const override { return true; }                          // 08
				bool                 GetIsStatic() const override { return isStatic; }                      // 09
				bool                 GetIsEmpty() const override { return false; }                          // 0A
				FunctionType         GetFunctionType() const override { return FunctionType::kNormal; }     // 0B
				std::uint32_t        GetUserFlags() const override { return userFlags; }                    // 0C
				const BSFixedString& GetDocString() const override { return docString; }                    // 0D
				void                 InsertLocals(StackFrame&) const override { return; }                   // 0E

				CallResult Call(const BSTSmartPointer<Stack>& a_stack, ErrorLogger& a_errorLogger, Internal::VirtualMachine& a_vm, bool a_inScriptTasklet) const override  // 0F
				{
					using func_t = decltype(&NativeFunctionBase::Call);
					static REL::Relocation<func_t> func{ REL::ID(2314780) };
					return func(this, a_stack, a_errorLogger, a_vm, a_inScriptTasklet);
				}

				const BSFixedString& GetSourceFilename() const override  // 10
				{
					static BSFixedString native{ "<native>"sv };
					return native;
				}

				bool TranslateIPToLineNumber(std::uint32_t, std::uint32_t& a_lineNumber) const override  // 11
				{
					a_lineNumber = 0;
					return false;
				}

				bool GetVarNameForStackIndex(std::uint32_t a_index, BSFixedString& a_variableName) const override  // 12
				{
					if (a_index < descTable.totalEntries) {
						assert(descTable.entries != nullptr);
						a_variableName = descTable.entries[a_index].first;
						return true;
					} else {
						a_variableName = "";
						return false;
					}
				}

				bool CanBeCalledFromTasklets() const override { return isCallableFromTasklet; }                               // 13
				void SetCallableFromTasklets(bool a_taskletCallable) override { isCallableFromTasklet = a_taskletCallable; }  // 14

				// add
				virtual bool HasStub() const = 0;                                                                                                                                           // 15
				virtual bool MarshallAndDispatch(Variable& a_self, Internal::VirtualMachine& a_vm, std::uint32_t a_stackID, Variable& a_retVal, const StackFrame& a_stackFrame) const = 0;  // 16

				// members
				BSFixedString        name;                            // 10
				BSFixedString        objName;                         // 18
				BSFixedString        stateName{ "" };                 // 20
				TypeInfo             retType;                         // 28
				Internal::VDescTable descTable;                       // 30
				bool                 isStatic;                        // 40
				bool                 isCallableFromTasklet{ false };  // 41
				bool                 isLatent;                        // 42
				std::uint32_t        userFlags{ 0 };                  // 44
				BSFixedString        docString;                       // 48
			};
			static_assert(sizeof(NativeFunctionBase) == 0x50);
		}
	}
}
