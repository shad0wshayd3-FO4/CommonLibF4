#pragma once

namespace RE
{
	class __declspec(novtable) BGSDamageType :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSDamageType };
		static constexpr auto VTABLE{ VTABLE::BGSDamageType };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kDMGT };

		struct Data
		{
		public:
			// members
			ActorValueInfo* resistance;  // 00
			MagicItem*      spell;       // 08
		};
		static_assert(sizeof(Data) == 0x10);

		// members
		Data data;  // 20
	};
	static_assert(sizeof(BGSDamageType) == 0x30);
}
