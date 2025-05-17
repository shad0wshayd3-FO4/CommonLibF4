#include "RE/I/IDEvent.h"

namespace RE
{
	template IDEvent*       InputEvent::As<IDEvent>();
	template const IDEvent* InputEvent::As<IDEvent>() const;
}
