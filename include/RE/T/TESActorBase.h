#pragma once

#include "RE/T/TESBoundAnimObject.h"
#include "RE/T/TESActorBaseData.h"
#include "RE/T/TESContainer.h"
#include "RE/T/TESSpellList.h"
#include "RE/T/TESAIForm.h"
#include "RE/T/TESFullName.h"
#include "RE/A/ActorValueOwner.h"
#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSSkinForm.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSAttackDataForm.h"
#include "RE/B/BGSPerkRankArray.h"
#include "RE/B/BGSPropertySheet.h"

namespace RE
{
	class __declspec(novtable) TESActorBase :
		public TESBoundAnimObject,         // 000
		public TESActorBaseData,           // 068
		public TESContainer,               // 0D0
		public TESSpellList,               // 0E8
		public TESAIForm,                  // 0F8
		public TESFullName,                // 120
		public ActorValueOwner,            // 130
		public BGSDestructibleObjectForm,  // 138
		public BGSSkinForm,                // 148
		public BGSKeywordForm,             // 158
		public BGSAttackDataForm,          // 178
		public BGSPerkRankArray,           // 188
		public BGSPropertySheet            // 1A0
	{
	public:
		static constexpr auto RTTI{ RTTI::TESActorBase };
		static constexpr auto VTABLE{ VTABLE::TESActorBase };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kNONE };

		// add
		virtual bool            GetHasPLSpecTex() const { return false; }    // 67
		virtual TESCombatStyle* GetCombatStyle() { return nullptr; }         // 68
		virtual void            SetCombatStyle(TESCombatStyle*) { return; }  // 69
		virtual TESForm*        GetAsForm() { return nullptr; }              // 6A
	};
	static_assert(sizeof(TESActorBase) == 0x1B0);
}
