#pragma once

namespace RE
{
	struct DEFAULT_OBJECT_DATA
	{
	public:
		// members
		const char* name;           // 00
		REX::EnumSet<ENUM_FORM_ID, std::uint8_t>        type;           // 08
		std::uint32_t                                   uniqueID;       // 0C
		REX::EnumSet<DEFAULT_OBJECT_TYPE, std::int32_t> doType;         // 10
		const char* newObjectName;  // 18
	};
	static_assert(sizeof(DEFAULT_OBJECT_DATA) == 0x20);
}
