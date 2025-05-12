#pragma once

namespace RE
{
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
		bool        running;   // 50
		bool        busy;      // 51
		BSEventFlag haveTask;  // 58
		// BSTCommonStaticMessageQueue<AsyncRequest, 8> asyncSaveLoadOperationQueue;  // 80
		std::byte pad80[0x780 - 0x80];
	};
	static_assert(sizeof(BGSSaveLoadThread) == 0x780);
}
