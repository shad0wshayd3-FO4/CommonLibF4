#include "RE/W/WorkbenchMenuBase.h"

#include "RE/P/PlayerCharacter.h"

namespace RE
{
	WorkbenchMenuBase::InitParams::InitParams()
	{
		workbenchFurniture.reset();
		inventorySource = RE::PlayerCharacter::GetPlayerHandle();
	}
}
