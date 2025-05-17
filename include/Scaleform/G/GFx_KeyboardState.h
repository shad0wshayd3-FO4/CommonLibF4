#pragma once

#include "Scaleform/R/RefCountBase.h"

namespace Scaleform::GFx
{
	class EventId;
	class InteractiveObject;

	class __declspec(novtable) alignas(0x08) KeyboardState :
		public RefCountBase<KeyboardState, 2>  // 00
	{
	public:
		class __declspec(novtable) IListener
		{
		public:
			virtual ~IListener();  // 00

			// add
			virtual void OnKeyDown(InteractiveObject* a_movie, const EventId& a_eventID, std::int32_t a_keyMask) = 0;  // 01
			virtual void OnKeyUp(InteractiveObject* a_movie, const EventId& a_eventID, std::int32_t a_keyMask) = 0;    // 02
			virtual void Update(const EventId& a_eventID) = 0;                                                         // 03
		};
		static_assert(sizeof(IListener) == 0x08);

		// members
		std::byte pad[0x688 - 0x10];  // 10 - TODO
	};
	static_assert(sizeof(KeyboardState) == 0x688);
}
