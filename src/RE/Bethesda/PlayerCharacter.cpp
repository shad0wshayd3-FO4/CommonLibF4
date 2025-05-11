#include "RE/Bethesda/PlayerCharacter.h"

#include "RE/Bethesda/BGSEntryPoint.h"
#include "RE/Bethesda/Calendar.h"
#include "RE/Bethesda/Settings.h"

namespace RE
{
	void PlayerCharacter::LockOutOfTerminal(ObjectRefHandle a_handle)
	{
		float TerminalLockoutTime{ 0.0f };
		if (auto INISettingCollection = RE::INISettingCollection::GetSingleton()) {
			if (auto setting = INISettingCollection->GetSetting("iTerminalLockoutTime:Gameplay")) {
				TerminalLockoutTime = static_cast<float>(setting->GetInt());
			}
		}

		BGSEntryPoint::HandleEntryPoint(RE::BGSEntryPoint::ENTRY_POINT::kModTerminalLockoutTime, this, &TerminalLockoutTime);
		if (auto Calendar = RE::Calendar::GetSingleton()) {
			auto TimeScale = Calendar->timeScale ? Calendar->timeScale->GetValue() : 0.0f;
			TerminalLockoutTime *= TimeScale * 0.00027799999f;
			TerminalLockoutTime += Calendar->GetHoursPassed();
		}

		lockedTerminals.emplace_back(a_handle, TerminalLockoutTime);
	}

	bool PlayerCharacter::IsLockedOutOfTerminal(ObjectRefHandle a_handle)
	{
		float HoursPassed{ 24.0f };
		if (auto Calendar = RE::Calendar::GetSingleton()) {
			HoursPassed = Calendar->GetHoursPassed();
		}

		for (std::uint32_t i = 0; i < lockedTerminals.size();) {
			auto& iter = lockedTerminals.at(i);
			if (HoursPassed <= iter.second) {
				i++;
				continue;
			}

			lockedTerminals.erase(&iter);
		}

		for (auto& iter : lockedTerminals) {
			if (iter.first == a_handle) {
				return true;
			}
		}

		return false;
	}
}
