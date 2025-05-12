#pragma once

namespace RE
{
	namespace BSSystemFileStreamer
	{
		struct ID
		{
		public:
			// members
			std::uint32_t id;  // 0
		};
		static_assert(sizeof(ID) == 0x4);
	}
}
