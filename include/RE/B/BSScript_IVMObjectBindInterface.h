#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	namespace BSScript
	{
		class Object;

		class __declspec(novtable) IVMObjectBindInterface
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__IVMObjectBindInterface };
			static constexpr auto VTABLE{ VTABLE::BSScript__IVMObjectBindInterface };

			virtual ~IVMObjectBindInterface();  // 00

			// add
			[[nodiscard]] virtual std::uint64_t GetBoundHandle(const BSTSmartPointer<Object>& a_objPtr) const = 0;                                                                   // 01
			virtual void                        TypeCanBeBound(const BSFixedString& a_className, std::uint64_t a_handle) = 0;                                                        // 02
			virtual void                        BindObject(BSTSmartPointer<Object>& a_objPtr, std::uint64_t a_handle, bool a_conditional) = 0;                                       // 03
			virtual void                        HandleLoadedBinding(BSTSmartPointer<Object>& a_objPtr, std::uint64_t a_handle, bool a_conditional) = 0;                              // 04
			virtual void                        RemoveAllBoundObjects(std::uint64_t a_handle) = 0;                                                                                   // 05
			virtual void                        RemoveAllDiskLoadedBoundObjects(std::uint64_t a_handle) = 0;                                                                         // 06
			virtual void                        HandleCObjectDeletion(std::uint64_t a_handle) = 0;                                                                                   // 07
			virtual void                        UnbindObject(const BSTSmartPointer<Object>& a_objPtr) = 0;                                                                           // 08
			virtual bool                        CreateObjectWithProperties(const BSFixedString& a_className, std::uint32_t a_numProperties, BSTSmartPointer<Object>& a_objPtr) = 0;  // 09
			virtual bool                        InitObjectProperties(BSTSmartPointer<Object>& a_objPtr, void* a_property, bool a_arg3) = 0;                                          // 0A
		};
		static_assert(sizeof(IVMObjectBindInterface) == 0x8);
	}
}
