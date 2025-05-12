#pragma once

namespace RE
{
	template <class T>
	class BSTValueRequestEvent
	{
	public:
		// members
		BSTValueEventSink<T>& valueEventSink;  // 00
	};
}
