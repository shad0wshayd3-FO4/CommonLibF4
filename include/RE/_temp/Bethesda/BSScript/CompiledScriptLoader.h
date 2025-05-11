#pragma once

#include "RE/Bethesda/BSContainer.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSScript/ErrorLogger.h"
#include "RE/Bethesda/BSScript/ILoader.h"
#include "RE/Bethesda/BSScript/Internal/ReadableStringTable.h"
#include "RE/Bethesda/BSScript/Object.h"
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
		class IStore;  // stub
		class Object;

		struct ILoader;

		namespace Internal
		{
			class ReadableStringTable;

		}
		namespace UnlinkedTypes
		{
			struct Object;  // stub
		}

		class __declspec(novtable) CompiledScriptLoader :
			public ILoader  // 00
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__CompiledScriptLoader };
			static constexpr auto VTABLE{ VTABLE::BSScript__CompiledScriptLoader };

			// override (ILoader)
			ILoader* Clone() const override;                                                         // 01
			void     SetScriptStore(const BSTSmartPointer<IStore>& a_newStore) override;             // 02
			bool     GetClass(const char* a_name, UnlinkedTypes::Object& a_unlinkedClass) override;  // 03

			// members
			ErrorLogger*                  errorHandler;      // 08
			BSTSmartPointer<IStore>       scriptStore;       // 10
			Internal::ReadableStringTable stringTable;       // 18
			std::int8_t                   fileMajorVersion;  // 30
			std::int8_t                   fileMinorVersion;  // 31
			std::int8_t                   loadFlags;         // 32
		};
		static_assert(sizeof(CompiledScriptLoader) == 0x38);
	}
}
