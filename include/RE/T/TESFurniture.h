#pragma once

#include "RE/T/TESObjectACTI.h"

namespace RE
{
	class __declspec(novtable) TESFurniture :
		public TESObjectACTI  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::TESFurniture };
		static constexpr auto VTABLE{ VTABLE::TESFurniture };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kFURN };

		struct EntryPointData
		{
		public:
			// members
			std::uint32_t entryPoint;  // 0
			std::uint32_t flags;       // 4
		};
		static_assert(sizeof(EntryPointData) == 0x8);

		[[nodiscard]] TESContainer* GetContainer()
		{
			using func_t = decltype(&TESFurniture::GetContainer);
			static REL::Relocation<func_t> func{ REL::ID(2198043) };
			return func(this);
		}

		// members
		BSTArray<EntryPointData>    entryPointDataArray;  // 148
		BGSAttachParentArray        attachParents;        // 160
		WorkbenchData               wbData;               // 178
		std::uint32_t               furnFlags;            // 17C
		TESForm*                    associatedForm;       // 180
		BSTArray<BSFurnitureMarker> markersArray;         // 188
	};
	static_assert(sizeof(TESFurniture) == 0x1A0);
}
