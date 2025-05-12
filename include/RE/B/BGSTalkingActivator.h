#pragma once

namespace RE
{
	class __declspec(novtable) BGSTalkingActivator :
		public TESObjectACTI  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSTalkingActivator };
		static constexpr auto VTABLE{ VTABLE::BGSTalkingActivator };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kTACT };

		// add
		virtual bool GetReflectedByAutoWater() { return false; }  // 67

		// members
		TESObjectREFR* tempRef;    // 148
		BGSVoiceType*  voiceType;  // 150
	};
	static_assert(sizeof(BGSTalkingActivator) == 0x158);
}
