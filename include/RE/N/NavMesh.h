#pragma once

#include "RE/B/BSNavmesh.h"
#include "RE/T/TESChildCell.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class __declspec(novtable) NavMesh :
		public TESForm,       // 00
		public TESChildCell,  // 20
		public BSNavmesh      // 28
	{
	public:
		static constexpr auto RTTI{ RTTI::NavMesh };
		static constexpr auto VTABLE{ VTABLE::NavMesh };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kNAVM };

		// add
		virtual void Save() { return; }                                                 // 4A
		virtual bool SavesBefore([[maybe_unused]] FORM* a_groupFORM) { return false; }  // 4B
		virtual bool SavesBefore([[maybe_unused]] TESForm* a_form) { return false; }    // 4C
		virtual bool ProcessBeforeSave() { return false; }                              // 4D
	};
	static_assert(sizeof(NavMesh) == 0x230);
}
