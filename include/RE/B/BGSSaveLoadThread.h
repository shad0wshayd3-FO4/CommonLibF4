#pragma once

#include "RE/B/BSThread.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSEventFlag.h"

namespace RE
{
	class BGSSaveLoadFile;

	class alignas(0x80) BGSSaveLoadThread :
		public BSThread  // 00
	{
	public:
		struct AsyncRequest
		{
		public:
			using TaskFinishedCallback_t = void (*)(bool);

			// members
			std::uint32_t          taskTypeID;            // 00
			BGSSaveLoadFile*       savefile;              // 08
			TaskFinishedCallback_t taskFinishedCallback;  // 10
			BSFixedString          previousSaveToDelete;  // 18
		};
		static_assert(sizeof(AsyncRequest) == 0x20);

		virtual ~BGSSaveLoadThread();  // 00

		// members
		bool        running;                                    // 50
		bool        busy;                                       // 51
		BSEventFlag haveTask;                                   // 58
		std::byte   asyncSaveLoadOperationQueue[0x780 - 0x80];  // 80 - BSTCommonStaticMessageQueue<AsyncRequest, 8>
	};
	static_assert(sizeof(BGSSaveLoadThread) == 0x780);
}
