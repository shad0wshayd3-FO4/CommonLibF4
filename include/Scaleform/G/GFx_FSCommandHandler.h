#pragma once

#include "Scaleform/G/GFx_State.h"

namespace Scaleform::GFx
{
	class Event;
	class Movie;

	class __declspec(novtable) FSCommandHandler :
		public State  // 00
	{
	public:
		FSCommandHandler() :
			State(StateType::kFSCommandHandler)
		{}

		virtual void HandleEvent(class Movie* pmovie, const class Event& event) = 0;
	};
	static_assert(sizeof(FSCommandHandler) == 0x18);
}
