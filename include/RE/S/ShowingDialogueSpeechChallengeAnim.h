#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	class ShowingDialogueSpeechChallengeAnim :
		public BSTValueEvent<bool>
	{
	public:
	};
	static_assert(sizeof(ShowingDialogueSpeechChallengeAnim) == 0x2);
}
