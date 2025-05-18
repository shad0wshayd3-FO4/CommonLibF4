#include "RE/K/KinectEvent.h"

namespace RE
{
	template KinectEvent*       InputEvent::As() noexcept;
	template const KinectEvent* InputEvent::As() const noexcept;
}
