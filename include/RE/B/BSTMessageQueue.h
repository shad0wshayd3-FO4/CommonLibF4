#pragma once

namespace RE
{
	template <class T>
	class __declspec(novtable) BSTMessageQueue
	{
	public:
		virtual ~BSTMessageQueue() = default;  // 00

		// add
		virtual bool Push(const T& a_message) = 0;     // 01
		virtual bool TryPush(const T& a_message) = 0;  // 02
		virtual bool Pop(T& a_message) = 0;            // 03
		virtual bool TryPop(T& a_message) = 0;         // 04
	};
}
