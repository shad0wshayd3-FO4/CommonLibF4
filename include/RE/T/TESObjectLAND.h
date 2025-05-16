#pragma once

#include "RE/N/NiPointer.h"
#include "RE/T/TESChildCell.h"
#include "RE/T/TESForm.h"
#include "RE/O/OBJ_LAND.h"

namespace RE
{
	class QueuedFile;

	class __declspec(novtable) TESObjectLAND :
		public TESForm,      // 00
		public TESChildCell  // 20
	{
	public:
		static constexpr auto RTTI{ RTTI::TESObjectLAND };
		static constexpr auto VTABLE{ VTABLE::TESObjectLAND };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kLAND };

		struct LoadedLandData;

		// members
		OBJ_LAND              data;            // 28
		TESObjectCELL*        parentCell;      // 30
		NiPointer<QueuedFile> queuedTextures;  // 38
		LoadedLandData*       loadedData;      // 40
	};
	static_assert(sizeof(TESObjectLAND) == 0x48);
}
