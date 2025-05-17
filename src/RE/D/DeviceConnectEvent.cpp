#include "RE/D/DeviceConnectEvent.h"

namespace RE
{
	template DeviceConnectEvent*       InputEvent::As() noexcept;
	template const DeviceConnectEvent* InputEvent::As() const noexcept;
}
