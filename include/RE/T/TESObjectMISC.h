#pragma once

#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSFeaturedItemMessage.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSMessageIcon.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BGSPickupPutdownSounds.h"
#include "RE/B/BGSTypedFormValuePair.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTTuple.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESIcon.h"
#include "RE/T/TESValueForm.h"
#include "RE/T/TESWeightForm.h"

namespace RE
{
	class __declspec(novtable) TESObjectMISC :
		public TESBoundObject,             // 000
		public TESFullName,                // 068
		public BGSModelMaterialSwap,       // 078
		public TESIcon,                    // 0B8
		public TESValueForm,               // 0C8
		public TESWeightForm,              // 0D8
		public BGSDestructibleObjectForm,  // 0E8
		public BGSMessageIcon,             // 0F8
		public BGSPickupPutdownSounds,     // 110
		public BGSKeywordForm,             // 128
		public BGSFeaturedItemMessage      // 148
	{
	public:
		static constexpr auto RTTI{ RTTI::TESObjectMISC };
		static constexpr auto VTABLE{ VTABLE::TESObjectMISC };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kMISC };

		// add
		virtual void SaveImpl() { return; }                    // 67
		virtual void LoadImpl(TESFile*, CHUNK_ID) { return; }  // 68

		[[nodiscard]] bool IsLooseMod() const noexcept
		{
			return ((formFlags & 0x80) != 0);
		}

		// members
		BSTArray<BSTTuple<TESForm*, BGSTypedFormValuePair::SharedVal>>* componentData;   // 158
		std::int8_t*                                                    displayIndices;  // 160
	};
	static_assert(sizeof(TESObjectMISC) == 0x168);
}
