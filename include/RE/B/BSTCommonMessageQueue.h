#pragma once

namespace RE
{
	template <class T>
	class __declspec(novtable) BSTCommonMessageQueue :
		public BSTMessageQueue<T>  // 00
	{
	public:
		// override (BSTMessageQueue<T>)
		bool Push(const T& a_message) override;     // 01
		bool TryPush(const T& a_message) override;  // 02
		bool Pop(T& a_message) override;            // 03
		bool TryPop(T& a_message) override;         // 04

		// add
		virtual bool DoTryPush([[maybe_unused]] const T& a_message) { return false; }  // 05
		virtual bool DoTryPop([[maybe_unused]] T& a_message) { return false; }         // 06

		// members
		std::uint32_t lock;  // 08
	};
}
