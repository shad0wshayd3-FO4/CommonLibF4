#pragma once

namespace RE
{
	class __declspec(novtable) BGSMaterialType :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSMaterialType };
		static constexpr auto VTABLE{ VTABLE::BGSMaterialType };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kMATT };

		// members
		TESModel          breakableFXModel;    // 20
		BGSMaterialType* parentType;          // 50
		BGSImpactDataSet* havokImpactDataSet;  // 58
		BSFixedString     materialName;        // 60
		std::uint32_t     materialID;          // 68
		NiColor           materialColor;       // 6C
		float             buoyancy;            // 78
		std::uint32_t     flags;               // 7C
	};
	static_assert(sizeof(BGSMaterialType) == 0x80);
}
