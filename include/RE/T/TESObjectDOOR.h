#pragma once

namespace RE
{
	class __declspec(novtable) TESObjectDOOR :
		public TESBoundAnimObject,         // 000
		public TESFullName,                // 068
		public BGSModelMaterialSwap,       // 078
		public TESMagicCasterForm,         // 100
		public TESMagicTargetForm,         // 100
		public BGSDestructibleObjectForm,  // 0B8
		public BGSOpenCloseForm,           // 0C8
		public BGSKeywordForm,             // 0D0
		public BGSNativeTerminalForm       // 0F0
	{
	public:
		static constexpr auto RTTI{ RTTI::TESObjectDOOR };
		static constexpr auto VTABLE{ VTABLE::TESObjectDOOR };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kDOOR };

		// members
		BGSLocalizedString      altOpenText;      // 108
		BGSLocalizedString      altCloseText;     // 110
		BGSSoundDescriptorForm* openSound;        // 118
		BGSSoundDescriptorForm* closeSound;       // 120
		BGSSoundDescriptorForm* loopSound;        // 128
		std::int8_t             flags;            // 130
		BSTArray<TESForm*>      randomTeleports;  // 138
	};
	static_assert(sizeof(TESObjectDOOR) == 0x150);
}
