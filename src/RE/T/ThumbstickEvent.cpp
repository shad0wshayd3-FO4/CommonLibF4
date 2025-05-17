#include "RE/T/ThumbstickEvent.h"

namespace RE
{
	template ThumbstickEvent*       InputEvent::As() noexcept;
	template const ThumbstickEvent* InputEvent::As() const noexcept;
}
