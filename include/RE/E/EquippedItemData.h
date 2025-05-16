#pragma once

#include "RE/N/NiRefObject.h"
#include "RE/E/EquippedItem.h"

namespace RE
{
	class BGSLoadFormBuffer;
	class BGSSaveFormBuffer;

	class __declspec(novtable) EquippedItemData :
		public NiRefObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::EquippedItemData };
		static constexpr auto VTABLE{ VTABLE::EquippedItemData };

		// add
		virtual void          SaveGame(BGSSaveFormBuffer* a_saveGameBuffer, const EquippedItem& a_equippedItem) const = 0;  // 02
		virtual void          LoadGame(BGSLoadFormBuffer* a_loadGameBuffer, const EquippedItem& a_equippedItem) = 0;        // 03
		virtual std::uint32_t GetObjectType() const = 0;                                                                    // 04
	};
	static_assert(sizeof(EquippedItemData) == 0x10);
}
