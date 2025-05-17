#pragma once

#include "RE/B/BGSSceneAction.h"

namespace RE
{
	class __declspec(novtable) BGSSceneActionRadio :
		public BGSSceneAction
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSSceneActionRadio };
		static constexpr auto VTABlE{ VTABLE::BGSSceneActionRadio };

		TESTopic*               topic;           // 20
		BGSSoundDescriptorForm* sound;           // 28
		BGSSoundOutput*         outputModel;     // 30
		BGSKeyword*             subtypeKeyword;  // 38
		BGSSoundDescriptorForm* topicSound;      // 40
		float                   soundDuration;   // 48
		std::uint32_t           soundID;         // 4C
		bool                    soundDone;       // 50
		TESTopic*               currentTopic;    // 58
		float                   failTimer;       // 60
	};
	static_assert(sizeof(BGSSceneActionRadio) == 0x68);
}
