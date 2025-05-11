#pragma once

#include "RE/Bethesda/BSTSmartPointer.h"
#include "RE/Bethesda/MemoryManager.h"
namespace RE
{
	namespace BSStorageDefs
	{
		enum class ErrorCode;
		enum class SeekMode;
		struct StreamBuffer
		{
			// TODO: add funcs
			std::size_t                    size;
			MemoryManager::AutoScrapBuffer buffer;
			void*                          ptrCur;
		};
	}

	class __declspec(novtable) BSStorage :
		public BSIntrusiveRefCounted
	{
	public:
		inline static constexpr auto RTTI = { RTTI::BSStorage };
		inline static constexpr auto VTABLE = { VTABLE::BSStorage };

		virtual ~BSStorage();  // 00

		// TODO: Read and Write are templates
		virtual std::size_t              GetSize() const = 0;                                                       // 01
		virtual std::size_t              GetPosition() const = 0;                                                   // 02
		virtual BSStorageDefs::ErrorCode Seek(std::size_t a_offset, BSStorageDefs::SeekMode a_seekMode) const = 0;  // 03
		virtual BSStorageDefs::ErrorCode Read(std::size_t a_numBytes, std::byte* a_bytes) const = 0;                // 04
		virtual BSStorageDefs::ErrorCode Write(std::size_t a_numBytes, const std::byte* a_bytes) = 0;               // 05

		// members
		bool                         unk0C;              // 0C
		bool                         unk0D;              // 0D
		uint16_t                     unk0E;              // 0E
		BSStorageDefs::StreamBuffer* buf;                // 10
		bool                         usingStreambuffer;  //18
	};
	static_assert(sizeof(BSStorage) == 0x20);
}
