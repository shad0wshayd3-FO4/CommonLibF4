#pragma once

#include "RE/T/TESForm.h"
#include "RE/T/TOPIC_INFO_DATA.h"
#include "RE/T/TESCondition.h"
#include "RE/R/ResponseListWrapper.h"

namespace RE
{
	class __declspec(novtable) TESTopicInfo :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESTopicInfo };
		static constexpr auto VTABLE{ VTABLE::TESTopicInfo };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kINFO };

		enum Flags
		{
			kInfoGroup = (1 << 6),
		};

		enum CHARISMA_CHALLENGE_DIFFICULTY : std::uint32_t
		{
			CC_CHALLENGE_NONE = 0,
			CC_CHALLENGE_EASY = 1,
			CC_CHALLENGE_MEDIUM = 2,
			CC_CHALLENGE_HARD = 3,
			CC_CHALLENGE_ALWAYS_SUCCEEDS = 4,
			CC_CHALLENGE_EASY_REPEATABLE = 5,
			CC_CHALLENGE_MEDIUM_REPEATABLE = 6,
			CC_CHALLENGE_HARD_REPEATABLE = 7,
			CC_CHALLENGE_COUNT = 8,
		};

		enum CHARISMA_CHALLENGE_SUCCESS : int32_t
		{
			CC_SUCCESS_FAIL = 0,
			CC_SUCCESS_SUCCEED = 1,
			CC_SUCCESS_COUNT = 2,
			CC_SUCCESS_NONE = -1,
		};

		TESTopicInfo* GetParentInfoGroup()
		{
			using func_t = decltype(&TESTopicInfo::GetParentInfoGroup);
			static REL::Relocation<func_t> func{ REL::ID(2208435) };
			return func(this);
		}

		CHARISMA_CHALLENGE_DIFFICULTY GetChallengeLevel()
		{
			using func_t = decltype(&TESTopicInfo::GetChallengeLevel);
			static REL::Relocation<func_t> func{ REL::ID(2208441) };
			return func(this);
		}

		CHARISMA_CHALLENGE_SUCCESS GetSuccessLevel()
		{
			using func_t = decltype(&TESTopicInfo::GetSuccessLevel);
			static REL::Relocation<func_t> func{ REL::ID(2208444) };
			return func(this);
		}

		[[nodiscard]] bool IsRandom() const noexcept { return data.flags.all(TOPIC_INFO_DATA::TOPIC_INFO_FLAGS::kRandom); }
		[[nodiscard]] bool IsRandomEnd() const noexcept { return data.flags.all(TOPIC_INFO_DATA::TOPIC_INFO_FLAGS::kRandomEnd); }
		[[nodiscard]] bool IsSayOnce() const noexcept { return data.flags.all(TOPIC_INFO_DATA::TOPIC_INFO_FLAGS::kSayOnce); }
		[[nodiscard]] bool StartSceneOnEnd() const noexcept { return data.flags.all(TOPIC_INFO_DATA::TOPIC_INFO_FLAGS::kStartSceneOnEnd); }

		// members
		TESTopic*           parentTopic;       // 20
		TESGlobal*          resetGlobal;       // 28
		TESTopicInfo*       dataInfo;          // 30
		TESCondition        objConditions;     // 38
		std::uint16_t       infoIndex;         // 40
		std::int8_t         subtitlePriority;  // 42
		bool                saidOnce;          // 43
		TOPIC_INFO_DATA     data;              // 44
		ResponseListWrapper responses;         // 48
	};
	static_assert(sizeof(TESTopicInfo) == 0x50);
}
