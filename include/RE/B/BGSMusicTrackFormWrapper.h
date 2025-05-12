#pragma once

#include "RE/B/BSIMusicTrack.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) BGSMusicTrackFormWrapper :
		public TESForm,       // 00
		public BSIMusicTrack  // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSMusicTrackFormWrapper };
		static constexpr auto VTABLE{ VTABLE::BGSMusicTrackFormWrapper };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kMUST };

		// members
		BGSMusicTrack* trackImpl;  // 30
	};
	static_assert(sizeof(BGSMusicTrackFormWrapper) == 0x38);
}
