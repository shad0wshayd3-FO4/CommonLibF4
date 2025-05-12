#pragma once

namespace RE
{
	class __declspec(novtable) BGSMaterialObject :
		public TESForm,          // 00
		public TESModel,         // 20
		public BSMaterialObject  // 50
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSMaterialObject };
		static constexpr auto VTABLE{ VTABLE::BGSMaterialObject };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kMATO };

		struct FILE_DATA
		{
		public:
			// members
			std::int8_t*  nuffer;      // 00
			std::uint32_t bufferSize;  // 08
		};
		static_assert(sizeof(FILE_DATA) == 0x10);

		// members
		BSTArray<FILE_DATA> fileData;  // A0
	};
	static_assert(sizeof(BGSMaterialObject) == 0xB8);
}
