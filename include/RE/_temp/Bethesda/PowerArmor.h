#pragma once

#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/Events.h"
#include "RE/Bethesda/HUDModes.h"

namespace RE
{
	namespace ExitPowerArmor
	{
		struct Event;
	}

	namespace PreloadPowerArmor
	{
		struct Event;
	}

	namespace PowerArmor
	{
		[[nodiscard]] inline bool ActorInPowerArmor(const Actor& a_actor)
		{
			using func_t = decltype(&ActorInPowerArmor);
			static REL::Relocation<func_t> func{ REL::ID(2219437) };
			return func(a_actor);
		}

		[[nodiscard]] inline bool PlayerInPowerArmor()
		{
			auto PlayerCharacter = PlayerCharacter::GetSingleton();
			return PlayerCharacter ? ActorInPowerArmor(*PlayerCharacter) : false;
		}

		[[nodiscard]] inline BGSKeyword* GetArmorKeyword()
		{
			using func_t = decltype(&GetArmorKeyword);
			static REL::Relocation<func_t> func{ REL::ID(961172) };
			return func();
		}

		[[nodiscard]] inline BGSKeyword* GetBatteryKeyword()
		{
			using func_t = decltype(&GetBatteryKeyword);
			static REL::Relocation<func_t> func{ REL::ID(1493537) };
			return func();
		}

		[[nodiscard]] inline TESAmmo* GetDefaultBatteryObject()
		{
			using func_t = decltype(&GetDefaultBatteryObject);
			static REL::Relocation<func_t> func{ REL::ID(1279247) };
			return func();
		}

		[[nodiscard]] inline bool IsPowerArmorBattery(const TESBoundObject* a_itemData)
		{
			using func_t = decltype(&IsPowerArmorBattery);
			static REL::Relocation<func_t> func{ REL::ID(1012910) };
			return func(a_itemData);
		}

		inline void SyncFurnitureVisualsToInventory(TESObjectREFR* a_furniture, bool a_force3DUpdate, BGSInventoryItem* a_tempItemToAdd, bool a_hideCore)
		{
			using func_t = decltype(&SyncFurnitureVisualsToInventory);
			static REL::Relocation<func_t> func{ REL::ID(1078979) };
			return func(a_furniture, a_force3DUpdate, a_tempItemToAdd, a_hideCore);
		}

		inline REL::Relocation<SettingT<GameSettingCollection>*> fNewBatteryCapacity{ REL::ID(1134204) };
	}
}
