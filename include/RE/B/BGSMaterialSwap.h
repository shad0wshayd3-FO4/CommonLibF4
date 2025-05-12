#pragma once

namespace RE
{
	class __declspec(novtable) BGSMaterialSwap :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSMaterialSwap };
		static constexpr auto VTABLE{ VTABLE::BGSMaterialSwap };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kMSWP };

		struct Entry
		{
		public:
			// members
			BSFixedString swapMaterial;         // 00
			float         colorRemappingIndex;  // 08
		};
		static_assert(sizeof(Entry) == 0x10);

		// members
		BSTHashMap<BSFixedString, Entry> swapMap;  // 20
	};
	static_assert(sizeof(BGSMaterialSwap) == 0x50);
}
