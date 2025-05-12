#include "RE/W/WorkbenchMenuBase.h"

namespace RE
{
	WorkbenchMenuBase::InitParams::InitParams()
	{
		workbenchFurniture.reset();
		inventorySource = RE::PlayerCharacter::GetPlayerHandle();
	}
}
