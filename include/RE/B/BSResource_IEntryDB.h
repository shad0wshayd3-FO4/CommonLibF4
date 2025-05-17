#pragma once

#include "RE/B/BSResource_EntryBucketQueue.h"

namespace RE::BSResource
{
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
		EntryBucketQueue<PostFlushNotify, 8> postFlushNotifyQueue;  // 00
	};
	static_assert(sizeof(IEntryDB) == 0xD0);
}
