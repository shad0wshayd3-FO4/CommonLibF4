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

	class BSSystemFile
	{
	public:
		struct Info
		{
		public:
			// members
			REX::W32::FILETIME accessTime;  // 00
			REX::W32::FILETIME modifyTime;  // 08
			REX::W32::FILETIME createTime;  // 10
			std::size_t        fileSize;    // 18
		};
		static_assert(sizeof(Info) == 0x20);

		// members
		std::uint32_t flags;  // 00
		void*         file;   // 08
	};
	static_assert(sizeof(BSSystemFile) == 0x10);
}
