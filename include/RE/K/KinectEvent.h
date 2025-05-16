#pragma once

#include "RE/I/IDEvent.h"
#include "RE/B/BSFixedString.h"

namespace RE
{
	class __declspec(novtable) KinectEvent :
		public IDEvent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::KinectEvent };
		static constexpr auto VTABLE{ VTABLE::KinectEvent };
		static constexpr auto TYPE{ INPUT_EVENT_TYPE::kKinect };

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~KinectEvent() = default;  // 00

		// members
		BSFixedString strHeard;  // 38
	};
	static_assert(sizeof(KinectEvent) == 0x40);

	extern template KinectEvent*       InputEvent::As() noexcept;
	extern template const KinectEvent* InputEvent::As() const noexcept;
}
