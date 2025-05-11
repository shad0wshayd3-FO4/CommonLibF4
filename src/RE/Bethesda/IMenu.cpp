#include "RE/Bethesda/IMenu.h"

#include "RE/Bethesda/PlayerCharacter.h"

namespace RE
{
	WorkbenchMenuBase::InitParams::InitParams()
	{
		workbenchFurniture.reset();
		inventorySource = RE::PlayerCharacter::GetPlayerHandle();
	}
}
