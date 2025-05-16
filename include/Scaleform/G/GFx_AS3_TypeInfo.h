#pragma once

namespace Scaleform::GFx::AS3
{
	class TypeInfo
	{
	public:
		// members
		std::uint32_t    flags;              // 00
		std::uint16_t    instanceSize;       // 04
		std::uint16_t    classMethodNum;     // 06
		std::uint16_t    classMemberNum;     // 08
		std::uint16_t    instanceMethodNum;  // 0A
		std::uint16_t    instanceMemberNum;  // 0C
		const char*      name;               // 10
		const char*      packageName;        // 18
		const TypeInfo*  parent;             // 20
		const TypeInfo** implements;         // 28
	};
	static_assert(sizeof(TypeInfo) == 0x30);
}
