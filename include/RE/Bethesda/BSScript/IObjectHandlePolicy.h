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
		struct __declspec(novtable) IObjectHandlePolicy
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__IObjectHandlePolicy };
			static constexpr auto VTABLE{ VTABLE::BSScript__IObjectHandlePolicy };

			virtual ~IObjectHandlePolicy() = default;  // 00

			// add
			virtual bool        HandleIsType(std::uint32_t a_type, std::size_t a_handle) const = 0;              // 01
			virtual bool        GetHandleType(std::size_t a_handle, std::uint32_t& a_type) const = 0;            // 02
			virtual bool        IsHandleLoaded(std::size_t a_handle) const = 0;                                  // 03
			virtual bool        IsHandleObjectAvailable(std::size_t a_handle) const = 0;                         // 04
			virtual bool        ShouldAttemptToCleanHandle(std::size_t a_handle) const = 0;                      // 05
			virtual std::size_t EmptyHandle() const = 0;                                                         // 06
			virtual std::size_t GetHandleForObject(std::uint32_t a_type, const void* a_object) const = 0;        // 07
			virtual bool        HasParent(std::size_t a_childHandle) const = 0;                                  // 08
			virtual std::size_t GetParentHandle(std::size_t a_childHandle) const = 0;                            // 09
			virtual std::size_t GetHandleScriptsMovedFrom(std::size_t a_newHandle) const = 0;                    // 0A
			virtual std::size_t GetSaveRemappedHandle(std::size_t a_saveHandle) const = 0;                       // 0B
			virtual void*       GetObjectForHandle(std::uint32_t a_type, std::size_t a_handle) const = 0;        // 0C
			virtual void        PersistHandle(std::size_t a_handle) = 0;                                         // 0D
			virtual void        ReleaseHandle(std::size_t a_handle) = 0;                                         // 0E
			virtual void        ConvertHandleToString(std::size_t a_handle, BSFixedString& a_string) const = 0;  // 0F
		};
		static_assert(sizeof(IObjectHandlePolicy) == 0x8);
	}
}
