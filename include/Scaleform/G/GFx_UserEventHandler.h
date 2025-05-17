#pragma once

#include "Scaleform/G/GFx_State.h"

namespace Scaleform::GFx
{
	class Event;
	class Movie;

	class __declspec(novtable) UserEventHandler :
		public State  // 00
	{
	public:
		UserEventHandler() :
			State(StateType::kUserEventHandler)
		{}

		virtual void HandleEvent(class Movie* pmovie, const class Event& event) = 0;
	};
	static_assert(sizeof(UserEventHandler) == 0x18);
}
