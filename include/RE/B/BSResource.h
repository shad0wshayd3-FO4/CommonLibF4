#pragma once

#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	namespace BSResource
	{
		enum class ErrorCode : std::uint32_t
		{
			kNone = 0x0,
			kNotExist = 0x1,
			kInvalidPath = 0x2,
			kFileError = 0x3,
			kInvalidType = 0x4,
			kMemoryError = 0x5,
			kBusy = 0x6,
			kInvalidParam = 0x7,
			kUnsupported = 0x8
		};

		enum class SeekMode
		{
			kSet = 0x0,
			kCurrent = 0x1,
			kEnd = 0x2
		};

		class Location;
		class Stream;

		struct FileID
		{
		public:
			[[nodiscard]] bool operator==(const FileID&) const noexcept = default;

			// members
			std::uint32_t file = 0;  // 0
			std::uint32_t ext = 0;   // 4
		};
		static_assert(sizeof(FileID) == 0x8);

		struct ID :
			public FileID  // 0
		{
		public:
			[[nodiscard]] bool operator==(const ID&) const noexcept = default;

			// members
			std::uint32_t dir = 0;  // 8
		};
		static_assert(sizeof(ID) == 0xC);

		struct Info
		{
		public:
			// members
			REX::W32::FILETIME modifyTime;  // 00
			REX::W32::FILETIME createTime;  // 08
			std::uint64_t      fileSize;    // 10
		};
		static_assert(sizeof(Info) == 0x18);

		[[nodiscard]] ErrorCode GetOrCreateStream(const char* a_fileName, BSTSmartPointer<Stream>& a_result, bool a_writable = false, Location* a_optionalStart = nullptr);

		inline void RegisterLocation(Location* a_location, std::uint32_t a_priority)
		{
			using func_t = decltype(&RegisterLocation);
			static REL::Relocation<func_t> func{ REL::ID(918408) };
			return func(a_location, a_priority);
		}
	}
}
