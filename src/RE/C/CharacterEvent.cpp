#include "RE/C/CharacterEvent.h"

namespace RE
{
	template CharacterEvent*       InputEvent::As() noexcept;
	template const CharacterEvent* InputEvent::As() const noexcept;
}
