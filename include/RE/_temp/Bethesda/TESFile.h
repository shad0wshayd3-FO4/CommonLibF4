#pragma once

#include "RE/Bethesda/BSStringT.h"
#include "RE/Bethesda/BSSystemFile.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTHashMap.h"
#include "RE/Bethesda/BSTList.h"
#include "RE/Bethesda/BSTSmartPointer.h"
#include "RE/NetImmerse/NiFile.h"

namespace RE
{
	enum class CHUNK_ID;
	enum class TES_RETURN_CODE;

	class TESObjectCELL;

	struct FORM_GROUP;
	struct TESBitArrayFile;

	union _ULARGE_INTEGER;  // NOLINT(bugprone-reserved-identifier)

	class __declspec(novtable) BSFile :
		public NiFile  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSFile };
		static constexpr auto VTABLE{ VTABLE::BSFile };

		class PageCache;

		// members
		bool                       useAuxBuffer;         // 050
		std::byte*                 auxBuffer;            // 058
		std::int32_t               auxTrueFilePos;       // 060
		std::uint32_t              auxBufferMinIndex;    // 064
		std::uint32_t              auxBufferMaxIndex;    // 068
		char                       fileName[260];        // 06C
		std::size_t                result;               // 170
		std::size_t                ioSize;               // 178
		std::size_t                trueFilePos;          // 180
		std::size_t                fileSize;             // 188
		bool                       virtualAlloc;         // 190
		BSTSmartPointer<PageCache> pageCache;            // 198
		BSSystemFileStreamer::ID   pathID;               // 1A0
		std::uint32_t              streamerPriority;     // 1A4
		std::int8_t                basePageOffset;       // 1A8
		bool                       readThroughStreamer;  // 1A9
	};
	static_assert(sizeof(BSFile) == 0x1B0);

	struct FORM
	{
	public:
		// members
		std::uint32_t form;            // 00
		std::uint32_t length;          // 04
		std::uint32_t flags;           // 08
		TESFormID     formID;          // 0C
		std::uint32_t versionControl;  // 10
		std::uint16_t formVersion;     // 14
		std::uint16_t vcVersion;       // 16
	};
	static_assert(sizeof(FORM) == 0x18);

	struct FILE_HEADER
	{
	public:
		// members
		float         version;     // 0
		std::uint32_t formCount;   // 4
		std::uint32_t nextFormID;  // 8
	};
	static_assert(sizeof(FILE_HEADER) == 0xC);

	class TESFile
	{
	public:
		struct InteriorCellOffsetDataStruct;

		enum class RecordFlag
		{
			kNone = 0,
			kMaster = 1 << 0,
			kAltered = 1 << 1,
			kChecked = 1 << 2,
			kActive = 1 << 3,
			kOptimizedFile = 1 << 4,
			kTempIDOwner = 1 << 5,
			kDelocalized = 1 << 7,
			kPrecalcDataOnly = 1 << 8,
			kSmallFile = 1 << 9
		};

		[[nodiscard]] std::uint8_t     GetCompileIndex() const noexcept { return compileIndex; }
		[[nodiscard]] std::string_view GetFilename() const noexcept { return { filename }; }
		[[nodiscard]] std::uint16_t    GetSmallFileCompileIndex() const noexcept { return smallFileCompileIndex; }
		[[nodiscard]] bool             IsActive() const noexcept { return GetCompileIndex() != 0xFF; }
		[[nodiscard]] bool             IsLight() const noexcept { return flags.all(RecordFlag::kSmallFile); };

		[[nodiscard]] bool CloseTES(bool a_forceClose)
		{
			using func_t = decltype(&TESFile::CloseTES);
			static REL::Relocation<func_t> func{ REL::ID(2192491) };
			return func(this, a_forceClose);
		}

		[[nodiscard]] bool GetChunkData(void* a_data, std::uint32_t a_maxSize)
		{
			using func_t = bool (TESFile::*)(void*, uint32_t);
			static REL::Relocation<func_t> func{ REL::ID(2192538) };
			return func(this, a_data, a_maxSize);
		}

		[[nodiscard]] bool GetChunkData(char* a_data)
		{
			return GetChunkData(a_data, 0);
		}

		[[nodiscard]] bool IsFormInMod(TESFormID a_formID) const
		{
			if (!IsLight() && (a_formID >> 24) == compileIndex) {
				return true;
			}
			if (IsLight() && (a_formID >> 24) == 0xFE && ((a_formID & 0x00FFF000) >> 12) == smallFileCompileIndex) {
				return true;
			}
			return false;
		}

		[[nodiscard]] std::uint32_t GetTESChunk()
		{
			using func_t = decltype(&TESFile::GetTESChunk);
			static REL::Relocation<func_t> func{ REL::ID(2192536) };
			return func(this);
		}

		[[nodiscard]] bool NextChunk()
		{
			using func_t = decltype(&TESFile::NextChunk);
			static REL::Relocation<func_t> func{ REL::ID(2192537) };
			return func(this);
		}

		[[nodiscard]] bool NextForm(bool a_skipIgnored)
		{
			using func_t = decltype(&TESFile::NextForm);
			static REL::Relocation<func_t> func{ REL::ID(2192527) };
			return func(this, a_skipIgnored);
		}

		[[nodiscard]] bool NextGroup()
		{
			using func_t = decltype(&TESFile::NextGroup);
			static REL::Relocation<func_t> func{ REL::ID(2192522) };
			return func(this);
		}

		[[nodiscard]] bool OpenTES(char* a_path, const char* a_filename, NiFile::OpenMode a_accessMode, bool a_lock)
		{
			using func_t = bool (TESFile::*)(char*, const char*, NiFile::OpenMode, bool);
			static REL::Relocation<func_t> func{ REL::ID(2192490) };
			return func(this, a_path, a_filename, a_accessMode, a_lock);
		}

		[[nodiscard]] bool OpenTES(NiFile::OpenMode a_accessMode, bool a_lock)
		{
			return OpenTES(path, filename, a_accessMode, a_lock);
		}

		// members
		REX::EnumSet<TES_RETURN_CODE, std::int32_t> lastError;                        // 000
		TESFile*                                    threadSafeParent;                 // 008
		BSTHashMap<std::uint32_t, TESFile*>         threadSafeFileMap;                // 010
		BSTSmartPointer<BSFile::PageCache>          pageCache;                        // 040
		BSFile*                                     lockedFile;                       // 048
		BSFile*                                     file;                             // 050
		TESBitArrayFile*                            formUserDataBitArray;             // 058
		TESBitArrayFile*                            formVersionBitArray;              // 060
		TESBitArrayFile*                            formIDBitArray;                   // 068
		char                                        filename[REX::W32::MAX_PATH];     // 070
		char                                        path[REX::W32::MAX_PATH];         // 174
		char*                                       buffer;                           // 278
		std::uint32_t                               bufferAllocSize;                  // 280
		std::uint32_t                               firstCellOffset;                  // 284
		std::uint32_t                               currCellOffset;                   // 288
		TESObjectCELL*                              currCell;                         // 290
		std::uint32_t                               currRefOffset;                    // 298
		FORM                                        currentform;                      // 29C
		REX::EnumSet<CHUNK_ID, std::int32_t>        currentchunkID;                   // 2B4
		std::uint32_t                               actualChunkSize;                  // 2B8
		std::uint32_t                               filesize;                         // 2BC
		std::uint32_t                               fileoffset;                       // 2C0
		std::uint32_t                               formoffset;                       // 2C4
		std::uint32_t                               chunkoffset;                      // 2C8
		FORM                                        saveform;                         // 2CC
		std::uint32_t                               saveformoffset;                   // 2E4
		std::uint32_t                               savechunkoffset;                  // 2E8
		BSSimpleList<FORM_GROUP*>                   groups;                           // 2F0
		bool                                        hasGroups;                        // 300
		BSSystemFile::Info                          fileInfo;                         // 308
		FILE_HEADER                                 fileHeaderInfo;                   // 328
		REX::EnumSet<RecordFlag, std::uint32_t>     flags;                            // 334
		BSSimpleList<char*>                         masters;                          // 338
		BSSimpleList<_ULARGE_INTEGER*>              mastersData;                      // 348
		std::uint32_t                               masterCount;                      // 358
		TESFile**                                   masterPtrs;                       // 360
		REX::W32::FILETIME                          deletedFormTime;                  // 368
		std::uint8_t                                compileIndex;                     // 370
		std::uint16_t                               smallFileCompileIndex;            // 372
		BSStringT<char>                             createdBy;                        // 378
		BSStringT<char>                             summary;                          // 388
		char*                                       decompressedFormBuffer;           // 398
		std::uint32_t                               decompressedFormBufferSize;       // 3A0
		void*                                       reservedDecompressionBuffer;      // 3A8
		std::uint32_t                               reservedDecompressionBufferSize;  // 3B0
		BSTArray<InteriorCellOffsetDataStruct>*     interiorCellOffsetData;           // 3B8
	};
	static_assert(sizeof(TESFile) == 0x3C0);
}
