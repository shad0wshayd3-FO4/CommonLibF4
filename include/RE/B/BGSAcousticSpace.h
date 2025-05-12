#pragma once

namespace RE
{
	class __declspec(novtable) BGSAcousticSpace :
		public TESBoundObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSAcousticSpace };
		static constexpr auto VTABLE{ VTABLE::BGSAcousticSpace };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kASPC };

		// members
		BGSSoundDescriptorForm* loopingSound;           // 68
		TESRegion*              soundRegion;            // 70
		BGSReverbParameters*    reverbType;             // 78
		std::uint16_t           weatherAttenMillibels;  // 80
		bool                    isInterior;             // 82
	};
	static_assert(sizeof(BGSAcousticSpace) == 0x88);
}
