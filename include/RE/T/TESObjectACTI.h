#pragma once

namespace RE
{
	class __declspec(novtable) TESObjectACTI :
		public TESBoundAnimObject,         // 000
		public TESFullName,                // 068
		public BGSModelMaterialSwap,       // 078
		public TESMagicTargetForm,         // 120
		public BGSDestructibleObjectForm,  // 0B8
		public BGSOpenCloseForm,           // 0C8
		public BGSKeywordForm,             // 0D0
		public BGSPropertySheet,           // 0F0
		public BGSForcedLocRefType,        // 100
		public BGSNativeTerminalForm,      // 110
		public BGSNavmeshableObject        // 120
	{
	public:
		static constexpr auto RTTI{ RTTI::TESObjectACTI };
		static constexpr auto VTABLE{ VTABLE::TESObjectACTI };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kACTI };

		// members
		BGSSoundDescriptorForm* soundLoop;      // 128
		BGSSoundDescriptorForm* soundActivate;  // 130
		TESWaterForm*           waterForm;      // 138
		std::uint16_t           flags;          // 140
	};
	static_assert(sizeof(TESObjectACTI) == 0x148);
}
