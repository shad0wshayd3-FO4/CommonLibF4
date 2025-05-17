#pragma once

namespace Scaleform
{
	using ThreadId = void*;

	inline ThreadId GetCurrentThreadId()
	{
		return reinterpret_cast<ThreadId>(
			static_cast<std::uintptr_t>(REX::W32::GetCurrentThreadId()));
	}
}
