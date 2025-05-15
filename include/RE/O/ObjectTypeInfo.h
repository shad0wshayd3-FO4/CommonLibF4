#pragma once

#include "RE/B/BSTArray.h"
#include "RE/I/IComplexType.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/B/BSFixedString.h"
#include "RE/T/TypeInfo.h"
#include "RE/V/Variable.h"
#include "RE/P/PropertyTypeInfo.h"

namespace RE
{
	namespace BSScript
	{
		class IFunction;
		class PropertyGroupInfo;

		class __declspec(novtable) ObjectTypeInfo :
			public IComplexType  // 00
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__ObjectTypeInfo };
			static constexpr auto VTABLE{ VTABLE::BSScript__ObjectTypeInfo };

			enum class LinkValidState : std::uint32_t
			{
				kNotLinked = 0x0,
				kCurrentlyLinking = 0x1,
				kLinkedInvalid = 0x2,
				kLinkedValid = 0x3
			};

			[[nodiscard]] std::uint32_t GetVariableCount() const noexcept
			{
				std::uint32_t count = 0;
				for (BSTSmartPointer iter{ this }; iter && iter->Valid(); iter = iter->parentTypeInfo) {
					count += iter->variableCount;
				}
				return count;
			}

			[[nodiscard]] bool Valid() const noexcept { return linkedValid == LinkValidState::kLinkedValid; }

			struct UnlinkedNativeFunction
			{
			public:
				// members
				UnlinkedNativeFunction*    next;  // 00
				BSTSmartPointer<IFunction> func;  // 08
			};
			static_assert(sizeof(UnlinkedNativeFunction) == 0x10);

			struct UserFlagInfo
			{
			public:
				enum : std::uintptr_t
				{
					kSetOnObject = 1 << 0
				};

				[[nodiscard]] BSFixedString GetUserFlag() const;

				// members
				std::uintptr_t data;  // 0
			};
			static_assert(sizeof(UserFlagInfo) == 0x8);

			struct VariableInfo
			{
			public:
				// members
				BSFixedString name;   // 00
				TypeInfo      type;   // 08
				std::uint64_t unk10;  // 10 - Not sure what this is, maybe a hash
			};
			static_assert(sizeof(VariableInfo) == 0x18);

			struct InitialValueInfo
			{
			public:
				// members
				std::uint32_t variableIndex;  // 00
				std::uint32_t pad04;          // 04
				Variable      initialValue;   // 08
			};
			static_assert(sizeof(InitialValueInfo) == 0x18);

			struct PropertyInfo
			{
			public:
				// members
				BSFixedString    name;  // 00
				PropertyTypeInfo info;  // 08
			};
			static_assert(sizeof(PropertyInfo) == 0x48);

			struct GlobalFuncInfo
			{
			public:
				// members
				BSTSmartPointer<IFunction> func;  // 00
			};
			static_assert(sizeof(GlobalFuncInfo) == 0x8);

			struct MemberFuncInfo
			{
			public:
				// members
				BSTSmartPointer<IFunction> func;  // 00
			};
			static_assert(sizeof(MemberFuncInfo) == 0x8);

			struct NamedStateInfo
			{
			public:
				enum : std::uint32_t
				{
					kFuncCountMask = 0x1FF,
					kFuncOffsetShift = 0x9
				};

				struct Func
				{
				public:
					// members
					BSTSmartPointer<IFunction> func;  // 00
				};
				static_assert(sizeof(Func) == 0x8);

				[[nodiscard]] constexpr std::uint32_t GetNumFuncs() const noexcept { return memberFunctionCount; }
				Func*                                 GetFuncIter();
				[[nodiscard]] const Func*             GetFuncIter() const;

				// members
				BSFixedString name;                     // 00
				std::uint32_t memberFunctionCount: 9;   // 08 - 0
				std::uint32_t memberFunctionOffset: 9;  // 09 - 1
				std::uint32_t pad0C;                    // 0C
			};
			static_assert(sizeof(NamedStateInfo) == 0x10);

			~ObjectTypeInfo();

			const char*               GetName() const;
			ObjectTypeInfo*           GetParent();
			const ObjectTypeInfo*     GetParent() const;
			virtual TypeInfo::RawType GetRawType() const override;

			[[nodiscard]] constexpr bool IsLinked() const noexcept
			{
				switch (linkedValid) {
					case LinkValidState::kLinkedInvalid:
					case LinkValidState::kLinkedValid:
						return true;
					default:
						return false;
				}
			}

			UnlinkedNativeFunction*       GetUnlinkedFunctionIter();
			const UnlinkedNativeFunction* GetUnlinkedFunctionIter() const;

			[[nodiscard]] constexpr std::uint32_t GetNumUserFlags() const noexcept { return userFlagCount; }
			UserFlagInfo*                         GetUserFlagIter();
			const UserFlagInfo*                   GetUserFlagIter() const;

			[[nodiscard]] constexpr std::uint32_t GetNumVariables() const noexcept { return variableCount; }
			std::uint32_t                         GetTotalNumVariables() const;
			VariableInfo*                         GetVariableIter();
			const VariableInfo*                   GetVariableIter() const;

			[[nodiscard]] constexpr std::uint32_t GetNumInitalValues() const noexcept { return initialValueCount; }
			InitialValueInfo*                     GetInitialValueIter();
			const InitialValueInfo*               GetInitialValueIter() const;

			[[nodiscard]] constexpr std::uint32_t GetNumProperties() const noexcept { return propertyCount; }
			PropertyInfo*                         GetPropertyIter();
			const PropertyInfo*                   GetPropertyIter() const;

			[[nodiscard]] constexpr std::uint32_t GetNumGlobalFuncs() const noexcept { return staticFunctionCount; }
			GlobalFuncInfo*                       GetGlobalFuncIter();
			const GlobalFuncInfo*                 GetGlobalFuncIter() const;

			[[nodiscard]] constexpr std::uint32_t GetNumMemberFuncs() const noexcept { return emptyStateMemberFunctionCount; }
			MemberFuncInfo*                       GetMemberFuncIter();
			const MemberFuncInfo*                 GetMemberFuncIter() const;

			[[nodiscard]] constexpr std::uint32_t GetNumNamedStates() const noexcept { return namedStateCount; }
			NamedStateInfo*                       GetNamedStateIter();
			const NamedStateInfo*                 GetNamedStateIter() const;

			[[nodiscard]] const BSFixedString* GetInitialState() const;
			std::uint32_t                      GetPropertyIndex(const BSFixedString& a_name) const;
			[[nodiscard]] constexpr bool       HasPropertyGroups() const;

			// members
			BSFixedString                                name;                               // 10
			BSTSmartPointer<ObjectTypeInfo>              parentTypeInfo;                     // 18
			BSFixedString                                docString;                          // 20
			BSTArray<BSTSmartPointer<PropertyGroupInfo>> propertyGroups;                     // 28
			LinkValidState                               linkedValid: 2;                     // 40:00 - 0 or 1 -> data == UnlinkedNativeFunction*, 2 or 3 -> data == normal progression
			std::uint32_t                                isConst: 1;                         // 40:02
			std::uint32_t                                userFlagCount: 5;                   // 40:03
			std::uint32_t                                variableCount: 10;                  // 40:08
			std::uint32_t                                variableUserFlagCount: 6;           // 40:18
			std::uint32_t                                initialValueCount: 10;              // 44:00
			std::uint32_t                                propertyCount: 10;                  // 44:10
			std::uint32_t                                staticFunctionCount: 9;             // 44:20
			std::uint32_t                                emptyStateMemberFunctionCount: 11;  // 48:00
			std::uint32_t                                namedStateCount: 7;                 // 48:11
			std::uint32_t                                initialState: 7;                    // 48:18
			void*                                        data;                               // 50

		private:
			void Dtor();
		};

		static_assert(sizeof(ObjectTypeInfo) == 0x58);
	}
}
