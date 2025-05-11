#pragma once

#include "RE/Bethesda/Atomic.h"
#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSTSingleton.h"
#include "RE/Bethesda/BSTSmartPointer.h"

namespace RE
{
	namespace BSResource
	{
		class Location;
		class Stream;

		template <class T>
		class EntryDB;

		struct DAP
		{
		public:
		};
		static_assert(std::is_empty_v<DAP>);

		class EntryBase
		{
		public:
			// members
			ID                            name;    // 00
			BSTAtomicValue<std::uint32_t> ctrl;    // 0C
			BSTSmartPointer<Stream>       stream;  // 10
		};
		static_assert(sizeof(EntryBase) == 0x18);

		class EntryDBBaseUtil
		{
		public:
			static bool ReleaseEntryAction(EntryBase* a_entry)
			{
				using func_t = decltype(&EntryDBBaseUtil::ReleaseEntryAction);
				static REL::Relocation<func_t> func{ REL::ID(777279) };
				return func(a_entry);
			}

			// members
			Location*     rootLocation;           // 00
			std::uint32_t resourcePriorityBase;   // 08
			bool          allowDeadLoadSkipping;  // 0C
		};
		static_assert(sizeof(EntryDBBaseUtil) == 0x10);

		template <class T>
		class EntryQueue
		{
		public:
			// members
			BSNonReentrantSpinLock lock;  // 00
			T*                     head;  // 08
			T**                    tail;  // 10
		};
		static_assert(sizeof(EntryQueue<void>) == 0x18);

		template <class T, std::uint32_t SIZE>
		class EntryBucketQueue
		{
		public:
			// members
			EntryQueue<T>          buckets[SIZE];  // 00
			volatile std::uint32_t step;           // ??
		};
		static_assert(sizeof(EntryBucketQueue<void, 8>) == 0xC8);

		class IEntryDB
		{
		public:
			class NotifyLoadDone
			{
			public:
				virtual ~NotifyLoadDone();  // 00

				// add
				virtual void operator()() = 0;  // 01
			};
			static_assert(sizeof(NotifyLoadDone) == 0x08);

			class PostFlushNotify
			{
			public:
				virtual ~PostFlushNotify();  // 00

				// add
				virtual bool DoOnNotify() = 0;    // 01
				virtual void DoOnFinalize() = 0;  // 02

				// members
				std::uint32_t    state;  // 08
				PostFlushNotify* next;   // 10
			};
			static_assert(sizeof(PostFlushNotify) == 0x18);

			virtual ~IEntryDB();  // 00

			// add
			virtual void          CancelLoads() = 0;                                                     // 01
			virtual void          FlushReleases() = 0;                                                   // 02
			virtual bool          DoLoadIfSameOrBetter(std::uint32_t a_priority) = 0;                    // 03
			virtual void          DoMergeLoadsFromTo(std::uint32_t a_from, std::uint32_t a_to) = 0;      // 04
			virtual std::uint32_t UserFlush(NotifyLoadDone* a_notify, std::uint32_t a_maxPriority) = 0;  // 05

			// members
			EntryBucketQueue<PostFlushNotify, 8> postFlushNotifyQueue;
		};
		static_assert(sizeof(IEntryDB) == 0xD0);

		template <class T_Type, class T_EntryDBTraitsCArgs>
		class Entry :
			public EntryBase
		{
		public:
			using U_Type = T_Type;
			using U_EntryDBTraitsCArgs = T_EntryDBTraitsCArgs;

			// members
			Entry<T_Type, T_EntryDBTraitsCArgs>* next;   // 00
			T_Type                               data;   // ??
			std::uint32_t                        flags;  // ??
		};

		template <class T_DBTraits, class T_EntryDB>
		class EntryDBTraits
		{
		public:
			using U_DBTraits = T_DBTraits;
			using U_EntryDB = T_EntryDB;

			class CArgs
			{
			public:
				// members
				T_DBTraits::ArgsType args;  // 00
				BSFixedString        name;  // ??
			};
		};
		static_assert(std::is_empty_v<EntryDBTraits<void, void>>);

		template <class T_Type, class T_EntryDBTraitsCArgs, class T_DAP, std::uint32_t T_SIZE>
		class EntryCacheTraits
		{
		public:
			using U_Entry = Entry<T_Type, T_EntryDBTraitsCArgs>;
		};
		static_assert(std::is_empty_v<EntryCacheTraits<void, void, void, 0>>);

		template <class T_EntryCacheTraits>
		class alignas(0x80) REntryCache
		{
		public:
			using U_EntryCacheTraits = T_EntryCacheTraits;

			// members
			BSTAtomicValue<std::uint32_t> ctrl;            // 00
			T_EntryCacheTraits::U_Entry** table;           // 08
			std::uint32_t                 tableSize;       // 10
			std::uint32_t                 tombstoneCount;  // 14
			std::uint32_t                 active;          // 18
			std::uint32_t                 maxActive;       // 1C
			std::uint32_t                 misses;          // 20
		};

		template <class T_Entry, class T_EntryDB>
		class RHandleType
		{
		public:
			using U_Entry = T_Entry;
			using U_EntryDB = T_EntryDB;

			// members
			T_Entry* entry;  // 00
		};

		template <class T_RHandleType, std::uint32_t T_SIZE>
		class StreamerTraits
		{
		public:
			using U_RHandleType = T_RHandleType;

			struct RBTNodeAccess
			{
			public:
			};
			static_assert(std::is_empty_v<RBTNodeAccess>);

			struct StreamRequest
			{
			public:
				// members
				std::uint64_t   keyHigh;         // 00
				std::uint64_t   keyLow;          // 08
				StreamRequest*  left;            // 10
				StreamRequest*  right;           // 18
				StreamRequest** root;            // 20
				std::uint64_t   parentAndBlack;  // 28
				StreamRequest** tableSlot;       // 30
				void*           entry;           // 38
			};
			static_assert(sizeof(StreamRequest) == 0x40);

			struct StreamRequestKey
			{
			public:
				// members
				const StreamRequest* req;  // 00
			};
			static_assert(sizeof(StreamRequestKey) == 0x08);
		};
		static_assert(std::is_empty_v<StreamerTraits<void, 0>>);

		// TODO: fix this
		template <class T_RHandleType, std::uint32_t T_SIZE>
		class Streamer
		{
		public:
			using U_RHandleType = T_RHandleType;

			// members
			StreamerTraits<T_RHandleType, T_SIZE>::StreamRequest* table[T_SIZE * 2];  // 00
																					  //	BSTLocklessQueue::ObjMultiProdCons<StreamerTraits<T_RHandleType, T_SIZE>::StreamRequest, T_SIZE, 0> queue;  // ??
			std::byte                                                        pad10000[0x70400 - 0x10000];
			typename T_RHandleType::U_Entry::U_EntryDBTraitsCArgs            cargs[T_SIZE];  // ??
			BSNonReentrantSpinLock                                           schedProtect;   // ??
			std::byte                                                        pad88404[0x88440 - 0x88404];
			BSResource::StreamerTraits<T_RHandleType, T_SIZE>::StreamRequest rescheduleSearchRequest;  // ??
			BSTAtomicValue<std::uint32_t>                                    IDGen;                    // ??
			StreamerTraits<T_RHandleType, T_SIZE>::StreamRequest*            root;                     // ??
			StreamerTraits<T_RHandleType, T_SIZE>::StreamRequest*            lowest;                   // ??
			StreamerTraits<T_RHandleType, T_SIZE>::StreamRequest*            tombstone;                // ??
			std::uint32_t                                                    tableActive;              // ??
			std::byte                                                        pad884A4[0x88500 - 0x884A4];
		};

		template <class T_EntryDBTraits>
		class EntryDBBase :
			public EntryDBBaseUtil,
			public T_EntryDBTraits::U_DBTraits
		{
		public:
			// members
			REntryCache<EntryCacheTraits<typename T_EntryDBTraits::U_DBTraits::U_Type, typename T_EntryDBTraits::CArgs, DAP, 64>>                                            cache;         // 00
			Streamer<RHandleType<Entry<typename T_EntryDBTraits::U_DBTraits::U_Type, typename T_EntryDBTraits::CArgs>, EntryDB<typename T_EntryDBTraits::U_DBTraits>>, 4096> streamer;      // ?? : 80
			EntryBucketQueue<Entry<typename T_EntryDBTraits::U_DBTraits::U_Type, typename T_EntryDBTraits::CArgs>, 512>                                                      releaseQueue;  // ??
		};

		template <class T_DBTraits>
		class EntryDB :
			public IEntryDB,
			public EntryDBBase<EntryDBTraits<T_DBTraits, BSResource::EntryDB<T_DBTraits>>>,
			public BSTSingletonSDM<EntryDB<T_DBTraits>>
		{
		public:
			virtual ~EntryDB();  // 00

			// override (IEntryDB)
			virtual void          CancelLoads() override;                                                     // 01
			virtual void          FlushReleases() override;                                                   // 02
			virtual bool          DoLoadIfSameOrBetter(std::uint32_t a_priority) override;                    // 03
			virtual void          DoMergeLoadsFromTo(std::uint32_t a_from, std::uint32_t a_to) override;      // 04
			virtual std::uint32_t UserFlush(NotifyLoadDone* a_notify, std::uint32_t a_maxPriority) override;  // 05
		};
	}
}
