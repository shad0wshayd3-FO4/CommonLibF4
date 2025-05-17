#include "RE/M/MouseMoveEvent.h"

namespace RE
{
	template MouseMoveEvent*       InputEvent::As() noexcept;
	template const MouseMoveEvent* InputEvent::As() const noexcept;
}
