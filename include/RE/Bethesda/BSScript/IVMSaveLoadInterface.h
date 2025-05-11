#pragma once

#include "RE/Bethesda/BSTSmartPointer.h"

namespace RE
{
	class BSStorage;

	namespace BSScript
	{
		class Object;
		class Array;
		class TypeInfo;
		class Stack;
		class Struct;

		struct IHandleReaderWriter;

		namespace Internal
		{
			class ReadableStringTable;
			class ReadableTypeTable;
			class WritableStringTable;
			class WritableTypeTable;
			class CodeTasklet;
		}

		class __declspec(novtable) IVMSaveLoadInterface
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__IVMSaveLoadInterface };
			static constexpr auto VTABLE{ VTABLE::BSScript__IVMSaveLoadInterface };

			virtual ~IVMSaveLoadInterface();  // 00

			virtual bool                                 SaveGame(BSStorage& a_storage, IHandleReaderWriter const& a_HandleReaderWriter, bool a_flag) = 0;                                                         //14307D940 	// 01
			virtual bool                                 LoadGame(BSStorage const& a_storage, IHandleReaderWriter const& a_HandleReaderWriter, bool& a_flag, bool& b_flag) = 0;                                    //14307D948 	// 02
			virtual void                                 MarkSaveInvalid(BSStorage& a_storage) = 0;                                                                                                                //14307D950 	// 03
			virtual unsigned short                       GetSaveGameVersion() const = 0;                                                                                                                           //14307D958 	// 04
			virtual void                                 CleanupSave() = 0;                                                                                                                                        //14307D960 	// 05
			virtual void                                 CleanupLoad() = 0;                                                                                                                                        //14307D968 	// 06
			virtual void                                 DropAllRunningData() = 0;                                                                                                                                 //14307D970 	// 07
			virtual std::uint64_t                        GetSaveHandleForObject(const Object* a_Object) const = 0;                                                                                                 //14307D978 	// 08
			virtual void                                 SetSaveHandleForObject(const Object* a_Object, std::uint64_t) = 0;                                                                                        //14307D980 	// 09
			virtual bool                                 GetObjectBySaveHandle(std::uint64_t, const TypeInfo& a_TypeInfo, BSTSmartPointer<Object, BSTSmartPointerIntrusiveRefCount>& a_object_pointer) const = 0;  //14307D988 	// 0A
			virtual bool                                 GetObjectBySaveHandle(std::uint64_t, BSTSmartPointer<Object, BSTSmartPointerIntrusiveRefCount>& a_object_pointer) const = 0;                              //14307D990 	// 0B
			virtual std::uint64_t                        GetSaveHandleForStruct(const Struct* a_Struct) const = 0;                                                                                                 //14307D998 	// 0C
			virtual void                                 SetSaveHandleForStruct(const Struct* a_Struct, std::uint64_t) = 0;                                                                                        //14307D9A0 	// 0D
			virtual bool                                 GetStructBySaveHandle(std::uint64_t, BSTSmartPointer<Struct, BSTSmartPointerIntrusiveRefCount>& a_object_pointer) const = 0;                              //14307D9A8 	// 0E
			virtual std::uint64_t                        GetSaveHandleForArray(const Array* a_Array) const = 0;                                                                                                    //14307D9B0 	// 0F
			virtual void                                 SetSaveHandleForArray(const Array* a_Array, std::uint64_t) = 0;                                                                                           //14307D9B8 	// 10
			virtual bool                                 GetArrayBySaveHandle(std::uint64_t handle, BSTSmartPointer<Array, BSTSmartPointerIntrusiveRefCount>& a_array_pointer) const = 0;                          //14307D9C0 	// 11
			virtual bool                                 GetStackByID(unsigned int, BSTSmartPointer<Stack, BSTSmartPointerIntrusiveRefCount>& a_stack_pointer) const = 0;                                          //14307D9C8 	// 12
			virtual const Internal::WritableStringTable& GetWritableStringTable() const = 0;                                                                                                                       //14307D9D0 	// 13
			virtual const Internal::WritableStringTable& GetWritableStringTable() = 0;                                                                                                                             //14307D9D8 	// 14
			virtual Internal::ReadableStringTable&       GetReadableStringTable() const = 0;                                                                                                                       //14307D9E0 	// 15
			virtual const Internal::WritableTypeTable&   GetWritableTypeTable() const = 0;                                                                                                                         //14307D9E8 	// 16
			virtual Internal::WritableTypeTable&         GetWritableTypeTable() = 0;                                                                                                                               //14307D9F0 	// 17
			virtual const Internal::ReadableTypeTable&   GetReadableTypeTable() const = 0;                                                                                                                         //14307D9F8 	// 18
			virtual bool                                 CreateEmptyTasklet(Stack* a_Stack, BSTSmartPointer<Internal::CodeTasklet, BSTSmartPointerIntrusiveRefCount>& a_tasklet_pointer) = 0;                      //14307DA00 	// 19
		};
		static_assert(sizeof(IVMSaveLoadInterface) == 0x8);
	}
}
