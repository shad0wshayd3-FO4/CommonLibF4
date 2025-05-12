#pragma once

namespace RE
{
	struct BGSLocalizedStrings
	{
		struct ScrapStringBuffer
		{
		public:
			[[nodiscard]] const char* GetString() const noexcept { return static_cast<const char*>(buffer.GetPtr()) + offset; }

			// members
			MemoryManager::AutoScrapBuffer buffer;  // 00
			std::size_t                    offset;  // 08
		};
		static_assert(sizeof(ScrapStringBuffer) == 0x10);
	};
	static_assert(std::is_empty_v<BGSLocalizedStrings>);
}
