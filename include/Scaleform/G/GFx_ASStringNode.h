#pragma once

namespace Scaleform::GFx
{
	class ASStringManager;

	class ASStringNode
	{
	public:
		// members
		const char*      data;     // 00
		ASStringManager* manager;  // 08
		union
		{
			ASStringNode* lower;
			ASStringNode* next;
		};  // 10
		std::uint32_t refCount;   // 18
		std::uint32_t hashFlags;  // 1C
		std::uint32_t size;       // 20
	};
	static_assert(sizeof(ASStringNode) == 0x28);
}
