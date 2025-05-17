#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class __declspec(novtable) TESSpellList :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESSpellList };
		static constexpr auto VTABLE{ VTABLE::TESSpellList };

		class SpellData
		{
		public:
			SpellData() :
				spells(nullptr),
				levSpells(nullptr),
				shouts(nullptr),
				numSpells(0),
				numLevSpells(0),
				numShouts(0)
			{
			}
			~SpellData() = default;

			F4_HEAP_REDEFINE_NEW(SpellData);

			void CopySpellList(const std::vector<TESLevSpell*>& a_copiedData)
			{
				const auto oldData = levSpells;

				const auto newSize = a_copiedData.size();
				const auto newData = calloc<TESLevSpell*>(newSize);
				std::ranges::copy(a_copiedData, newData);

				numLevSpells = static_cast<std::uint32_t>(newSize);
				levSpells = newData;

				free(oldData);
			}

			void CopySpellList(const std::vector<SpellItem*>& a_copiedData)
			{
				const auto oldData = spells;

				const auto newSize = a_copiedData.size();
				const auto newData = calloc<SpellItem*>(newSize);
				std::ranges::copy(a_copiedData, newData);

				numSpells = static_cast<std::uint32_t>(newSize);
				spells = newData;

				free(oldData);
			}

			bool AddLevSpells(const std::vector<TESLevSpell*>& a_levSpells)
			{
				std::vector<TESLevSpell*> copiedData{ levSpells, levSpells + numLevSpells };
				std::ranges::remove_copy_if(a_levSpells, std::back_inserter(copiedData), [&](auto& spell) {
					return std::ranges::find(copiedData, spell) != copiedData.end();
				});
				CopySpellList(copiedData);
				return true;
			}

			bool AddSpells(const std::vector<SpellItem*>& a_spells)
			{
				std::vector<SpellItem*> copiedData{ spells, spells + numSpells };
				std::ranges::remove_copy_if(a_spells, std::back_inserter(copiedData), [&](auto& spell) {
					return std::ranges::find(copiedData, spell) != copiedData.end();
				});
				CopySpellList(copiedData);
				return true;
			}

			std::optional<std::uint32_t> GetIndex(const SpellItem* a_spell) const
			{
				if (spells) {
					for (std::uint32_t i = 0; i < numSpells; i++) {
						if (spells[i] == a_spell) {
							return i;
						}
					}
				}
				return std::nullopt;
			}

			std::optional<std::uint32_t> GetIndex(const TESLevSpell* a_levSpell) const
			{
				if (levSpells) {
					for (std::uint32_t i = 0; i < numLevSpells; i++) {
						if (levSpells[i] == a_levSpell) {
							return i;
						}
					}
				}
				return std::nullopt;
			}

			bool RemoveLevSpells(const std::vector<TESLevSpell*>& a_levSpells)
			{
				std::vector<TESLevSpell*> copiedData{ levSpells, levSpells + numLevSpells };
				if (std::erase_if(copiedData, [&](auto& spell) { return std::ranges::find(a_levSpells, spell) != a_levSpells.end(); }) > 0) {
					CopySpellList(copiedData);
					return true;
				}
				return false;
			}

			bool RemoveSpells(const std::vector<SpellItem*>& a_spells)
			{
				std::vector<SpellItem*> copiedData{ spells, spells + numSpells };
				if (std::erase_if(copiedData, [&](auto& spell) { return std::ranges::find(a_spells, spell) != a_spells.end(); }) > 0) {
					CopySpellList(copiedData);
					return true;
				}
				return false;
			}

			// members
			SpellItem**   spells;        // 00
			TESLevSpell** levSpells;     // 08
			TESShout**    shouts;        // 10
			std::uint32_t numSpells;     // 18
			std::uint32_t numLevSpells;  // 1C
			std::uint32_t numShouts;     // 20
		};
		static_assert(sizeof(SpellData) == 0x28);

		bool AddSpell(TESForm* a_spell)
		{
			using func_t = decltype(&TESSpellList::AddSpell);
			static REL::Relocation<func_t> func{ REL::ID(1312083) };
			return func(this, a_spell);
		}

		// members
		SpellData* spellData;  // 08
	};
	static_assert(sizeof(TESSpellList) == 0x10);
}
