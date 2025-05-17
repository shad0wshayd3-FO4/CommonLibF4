#include "RE/B/ButtonEvent.h"

namespace RE
{
	template ButtonEvent*       InputEvent::As() noexcept;
	template const ButtonEvent* InputEvent::As() const noexcept;
}
