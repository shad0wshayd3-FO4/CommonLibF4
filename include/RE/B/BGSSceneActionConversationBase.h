#pragma once

namespace RE
{
	class __declspec(novtable) BGSSceneActionConversationBase :
		public BGSSceneAction
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSceneActionConversationBase };
		static constexpr auto VTABLE{ VTABLE::BGSSceneActionConversationBase };

		TESTopic*               responseTopics[4];            // 20
		BGSKeyword*             pResponseSubtypeKeywords[4];  // 40
		BGSSoundOutput*         pOutputModel;                 // 60
		BSTArray<std::uint32_t> headTrackTargetA;             // 68
		std::uint32_t           headTargetValue;              // 80
		float                   headTrackChangeTimer;         // 84
		TESTopic*               currentTopic;                 // 88
	};
	static_assert(sizeof(BGSSceneActionConversationBase) == 0x90);
}
