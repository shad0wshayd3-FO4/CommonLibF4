#pragma once

namespace Scaleform
{
	class LogMessageId
	{
	public:
		LogMessageId(std::int32_t a_id) :
			id(a_id)
		{}

		~LogMessageId() noexcept {}

		// members
		std::int32_t id;  // 0
	};
	static_assert(sizeof(LogMessageId) == 0x4);
}
