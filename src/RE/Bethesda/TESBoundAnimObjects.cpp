#include "RE/Bethesda/TESBoundAnimObjects.h"

#include "RE/Bethesda/PlayerCharacter.h"
#include "RE/Bethesda/TESRace.h"

namespace RE
{
	void TESNPC::CopyPerkRankArray(const std::vector<PerkRankData>& a_copiedData)
	{
		const auto oldData = perks;

		const auto newSize = a_copiedData.size();
		const auto newData = calloc<PerkRankData>(newSize);
		std::ranges::copy(a_copiedData, newData);

		perkCount = static_cast<std::uint32_t>(newSize);
		perks = newData;

		free(oldData);
	}

	bool TESNPC::AddPerks(const std::vector<BGSPerk*>& a_perks, std::int8_t a_rank)
	{
		std::vector<PerkRankData> copiedData{ perks, perks + perkCount };
		std::ranges::for_each(a_perks, [&](auto& perk) {
			if (!GetPerkIndex(perk)) {
				const auto newPerk = new PerkRankData(perk, a_rank);
				copiedData.push_back(*newPerk);
			}
		});
		CopyPerkRankArray(copiedData);
		return true;
	}

	bool TESNPC::ContainsKeyword(std::string_view a_editorID) const
	{
		if (ContainsKeywordString(a_editorID)) {
			return true;
		}
		if (const auto npcRace = GetFormRace(); npcRace && npcRace->ContainsKeywordString(a_editorID)) {
			return true;
		}
		return false;
	}

	bool TESNPC::HasApplicableKeywordString(std::string_view a_editorID) const
	{
		if (HasKeywordString(a_editorID)) {
			return true;
		}
		if (const auto npcRace = GetFormRace(); npcRace && npcRace->HasKeywordString(a_editorID)) {
			return true;
		}
		return false;
	}

	bool TESNPC::RemovePerks(const std::vector<BGSPerk*>& a_perks)
	{
		std::vector<PerkRankData> copiedData{ perks, perks + perkCount };
		if (std::erase_if(copiedData, [&](auto& perkRank) { return std::ranges::find(a_perks, perkRank.perk) != a_perks.end(); }) > 0) {
			CopyPerkRankArray(copiedData);
			return true;
		}
		return false;
	}

	bool TESNPC::UsingAlternateHeadPartList() const
	{
		if (const auto player = PlayerCharacter::GetSingleton(); IsPlayer() && player) {
			const auto& map = GetAlternateHeadPartListMap();
			return player->charGenRace && player->charGenRace != formRace && map.contains(player->GetNPC());
		} else {
			return originalRace && originalRace != formRace;
		}
	}
}
