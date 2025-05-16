#pragma once

namespace Scaleform
{
	class String
	{
	public:
		struct DataDesc
		{
		public:
			// members
			std::uint64_t         size;      // 00
			volatile std::int32_t refCount;  // 08
			char                  data[1];   // 0C
		};
		static_assert(sizeof(DataDesc) == 0x10);

		const char* c_str()
		{
			return (const char*)((heapTypeBits & 0xFFFFFFFFFFFFFFFC) + 12);
		}

		bool empty()
		{
			return (((heapTypeBits & 0xFFFFFFFFFFFFFFFC) & 0x7FFFFFFFFFFFFFFF) == 0);
		}

		// members
		union
		{
			DataDesc*     data;
			std::uint64_t heapTypeBits;
		};  // 00
	};
	static_assert(sizeof(String) == 0x08);
}
