#include "RE/C/CursorMoveEvent.h"

namespace RE
{
	template CursorMoveEvent*       InputEvent::As() noexcept;
	template const CursorMoveEvent* InputEvent::As() const noexcept;
}
