#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSScript/IObjectProcessor.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTSmartPointer.h"

namespace RE
{
	namespace BSScript
	{
		class ErrorLogger;

		namespace Internal
		{
			class VirtualMachine;
		}

		class __declspec(novtable) LinkerProcessor :
			public IObjectProcessor
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__LinkerProcessor };
			static constexpr auto VTABLE{ VTABLE::BSScript__LinkerProcessor };

			virtual ~LinkerProcessor();  // 00

			// override (IObjectProcessor)
			virtual IObjectProcessor* Clone() override;                                    // 01
			virtual void              SetLoader(ILoader* a_loader) override;               // 02 - { loader = a_loader; }
			virtual bool              Process(const BSFixedString& a_className) override;  // 03

			// members
			Internal::VirtualMachine*   virtualMachine;      // 08  //size 0x8
			ErrorLogger*                errorLogger;         // 10  //size 0x8
			ILoader*                    loader;              // 18  //size 0x8
			std::uint64_t               unk20;               // 20
			char*                       unk28;               // 28
			BSScrapArray<BSFixedString> loadedParents;       // 30 //size 0x20
			BSScrapArray<BSFixedString> objectsToTypecheck;  // 50 //size 0x20
			BSScrapArray<BSFixedString> processQueue;        // 70 //size 0x20

			BSTHashMap<BSFixedString, BSTSmartPointer<ObjectTypeInfo>>* objectTypeInfoMap;  // 90 //size 0x8
			BSTHashMap<BSFixedString, BSTSmartPointer<StructTypeInfo>>* structTypeInfoMap;  // 98 //size 0x8
		};
		static_assert(sizeof(LinkerProcessor) == 0xA0);
	}
}
