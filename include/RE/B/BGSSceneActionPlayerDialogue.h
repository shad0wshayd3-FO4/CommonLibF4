#pragma once

namespace RE
{
	class __declspec(novtable) BGSSceneActionPlayerDialogue :
		public BGSSceneActionConversationBase
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSceneActionPlayerDialogue };
		static constexpr auto VTABlE{ VTABLE::BGSSceneActionPlayerDialogue };

		std::uint64_t dialogueTarget;                  // 90
		TESTopic*     pNPCResponseTopics[4];           // 98
		BGSKeyword*   pNPCResponseSubtypeKeywords[4];  // B8
		TESTopic*     pTopic;                          // D8
		std::uint32_t playerInput;                     // E0

		TESTopicInfo* GetCurrentTopicInfo(BGSScene* a_parentScene, TESObjectREFR* a_target, std::uint32_t a_type)
		{
			using func_t = decltype(&BGSSceneActionPlayerDialogue::GetCurrentTopicInfo);
			static REL::Relocation<func_t> func{ REL::ID(2196825) };
			return func(this, a_parentScene, a_target, a_type);
		}
	};
	static_assert(sizeof(BGSSceneActionPlayerDialogue) == 0xE8);
}
