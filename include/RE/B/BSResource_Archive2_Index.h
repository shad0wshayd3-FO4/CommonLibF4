#pragma once

#include "RE/B/BSBTreeFile.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSTSmallIndexScatterTable.h"
#include "RE/B/BSSpinLock.h"
#include "RE/B/BSResource_ID.h"
#include "RE/B/BSResource_AsyncStream.h"
#include "RE/B/BSResource_Stream.h"

namespace RE::BSResource
{
	class Location;

	namespace Archive2
	{
		struct RegisteredEvent;
		struct ClearRegistryEvent;

		class __declspec(novtable) Index :
			public BSTEventSink<RegisteredEvent>,    // 0000
			public BSTEventSink<ClearRegistryEvent>  // 0008
		{
		public:
			static constexpr auto RTTI{ RTTI::BSResource__Archive2__Index };
			static constexpr auto VTABLE{ VTABLE::BSResource__Archive2__Index };

			class Pager;
			struct NameIDAccess;

			struct Chunk
			{
			public:
				// members
				std::uint64_t dataFileOffset = 0;    // 00
				std::uint32_t compressedSize = 0;    // 08
				std::uint32_t uncompressedSize = 0;  // 0C
			};
			static_assert(sizeof(Chunk) == 0x10);

			struct Loose
			{
			public:
				// members
				Location*     location = nullptr;  // 00
				BSFixedString nameText;            // 08
			};
			static_assert(sizeof(Loose) == 0x10);

			struct EntryHeader
			{
			public:
				[[nodiscard]] bool IsChunk() const noexcept { return this->chunkOffsetOrType != 0; }
				[[nodiscard]] bool IsLoose() const noexcept { return this->chunkOffsetOrType == 0; }

				// members
				ID            nameID;                 // 00
				std::uint8_t  dataFileIndex = 0;      // 0C
				std::uint8_t  chunkCount = 0;         // 0D
				std::uint16_t chunkOffsetOrType = 0;  // 0E
			};
			static_assert(sizeof(EntryHeader) == 0x10);

			class Entry :
				public EntryHeader  // 00
			{
			public:
				~Entry()
				{
					if (this->IsLoose()) {
						this->loose.~Loose();
					} else {
						this->chunk.~Chunk();
					}
				}

				// members
				union
				{
					Chunk     chunk;
					Loose     loose;
					std::byte buffer[std::max(sizeof(Chunk), sizeof(Loose))] = {};
				};  // 10
				BSFixedString stringName;  // 20
			};
			static_assert(sizeof(Entry) == 0x28);

			class CursorWithEntry :
				public BSBTreeFile::BPTree<Pager, BSBTreeFile::PGFSEDL<Entry, ID, 4096>, 16>::Cursor  // 000
			{
			public:
				// members
				Entry e;  // 148
			};
			static_assert(sizeof(CursorWithEntry) == 0x170);

			// members
			BSTSmallIndexScatterTable<ID, NameIDAccess>                           nameTable;             // 0010
			BSTSmartPointer<Stream>                                               dataFiles[256];        // 0030
			BSTSmartPointer<AsyncStream>                                          asyncDataFiles[256];   // 0830
			ID                                                                    dataFileNameIDs[256];  // 1030
			std::uint32_t                                                         dataFileCount;         // 1C30
			BSBTreeFile::BPTree<Pager, BSBTreeFile::PGFSEDL<Entry, ID, 4096>, 16> tr;                    // 1C38
			BSReadWriteLock                                                       lock;                  // 1C58
		};
		static_assert(sizeof(Index) == 0x1C60);
	}
}
