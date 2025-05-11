#pragma once

#include "RE/Bethesda/BSContainer.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSScript/IComplexType.h"
#include "RE/Bethesda/BSScript/ObjectTypeInfo.h"
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
		class IComplexType;
		class ObjectTypeInfo;
		class TypeInfo;
		class Variable;

		class __declspec(novtable) StructTypeInfo :
			public IComplexType  // 00
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__StructTypeInfo };
			static constexpr auto VTABLE{ VTABLE::BSScript__StructTypeInfo };

			enum class LinkValidState
			{
				kNotLinked = 0x0,
				kCurrentlyLinking = 0x1,
				kLinkedInvalid = 0x2,
				kLinkedValid = 0x3
			};

			struct StructVar
			{
			public:
				// members
				Variable      initialValue;  // 00
				TypeInfo      varType;       // 10
				BSFixedString docString;     // 18
				std::uint32_t userFlags;     // 20
				bool          isConst;       // 24
			};
			static_assert(sizeof(StructVar) == 0x28);

			const char* GetName() const
			{
				return name.c_str();
			}

			virtual TypeInfo::RawType GetRawType() const override;

			// members
			BSFixedString                              name;                   // 10
			BSTSmartPointer<ObjectTypeInfo>            containingObjTypeInfo;  // 18
			BSTArray<StructVar>                        variables;              // 20
			BSTHashMap<BSFixedString, std::uint32_t>   varNameIndexMap;        // 38
			REX::EnumSet<LinkValidState, std::int32_t> linkedValid;            // 68
		};
		static_assert(sizeof(StructTypeInfo) == 0x70);
	}
}
