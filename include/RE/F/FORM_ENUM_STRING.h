#pragma once

namespace RE
{
	struct FORM_ENUM_STRING
	{
	public:
		// members
		ENUM_FORM_ID  formID;      // 00
		const char*   formString;  // 08 - "GRUP"
		std::uint32_t formCode;    // 10 - 'PURG'
	};
	static_assert(sizeof(FORM_ENUM_STRING) == 0x18);
}
