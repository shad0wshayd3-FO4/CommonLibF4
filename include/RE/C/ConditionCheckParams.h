#pragma once

namespace RE
{
	class BGSPackageDataList;
	class BGSStoryEvent;

	struct ConditionCheckParams
	{
	public:
		// members
		TESObjectREFR*            actionRef{ nullptr };           // 00
		TESObjectREFR*            targetRef{ nullptr };           // 08
		const TESQuest*           scopeQuest{ nullptr };          // 10
		const BGSStoryEvent*      scopeEvent{ nullptr };          // 18
		Actor*                    scopeActor{ nullptr };          // 20
		const BGSPackageDataList* runningPackageData{ nullptr };  // 28
		BGSMod::Template::Item*   objectTemplateItem{ nullptr };  // 30
		const TESForm*            extraForms[5]{ nullptr };       // 38
		std::uint32_t             extraFormCount{ 0 };            // 60
		bool                      outDispFailure{ false };        // 64
	};
	static_assert(sizeof(ConditionCheckParams) == 0x68);
}
