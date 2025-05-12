#pragma once

namespace RE
{
	// TODO: This isn't accurate, this is contains a statically allocated BSTLocklessQueue, figure out how to do this
	template <class T, std::size_t SIZE>
	class __declspec(novtable) alignas(0x80) BSTCommonStaticMessageQueue :
		public BSTMessageQueue<T>  // 00
	{
	public:
		virtual ~BSTCommonStaticMessageQueue();  // 00

		// override (BSTMessageQueue<T>)
		bool Push(const T& a_message) override;     // 01
		bool TryPush(const T& a_message) override;  // 02
		bool Pop(T& a_message) override;            // 03
		bool TryPop(T& a_message) override;         // 04

		// members
		alignas(0x80) char queueBuffer[sizeof(T) * SIZE];              // 10
		BSTLocklessQueue::ObjMultiProdCons<T, 128, 0>* locklessQueue;  // ??
	};
}
