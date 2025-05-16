#pragma once

#include "RE/B/BSTSingleton.h"
#include "RE/P/PipboyInventoryData.h"
#include "RE/P/PipboyLogData.h"
#include "RE/P/PipboyMapData.h"
#include "RE/P/PipboyObject.h"
#include "RE/P/PipboyPerksData.h"
#include "RE/P/PipboyPlayerInfoData.h"
#include "RE/P/PipboyQuestData.h"
#include "RE/P/PipboyRadioData.h"
#include "RE/P/PipboySpecialData.h"
#include "RE/P/PipboyStatsData.h"
#include "RE/P/PipboyStatusData.h"
#include "RE/P/PipboyThrottleManager.h"
#include "RE/P/PipboyWorkshopData.h"

namespace RE
{
	class _declspec(novtable) PipboyDataManager :
		public BSTSingletonSDM<PipboyDataManager>  // 00
	{
	public:
		[[nodiscard]] static PipboyDataManager* GetSingleton()
		{
			static REL::Relocation<PipboyDataManager**> singleton{ REL::ID(2689086) };
			return *singleton;
		}

		// members
		PipboyObject          rootObject;       // 008
		PipboyStatsData       statsData;        // 0A0
		PipboySpecialData     specialData;      // 1D8
		PipboyPerksData       perksData;        // 280
		PipboyInventoryData   inventoryData;    // 358
		PipboyQuestData       questData;        // 4F0
		PipboyWorkshopData    workshopData;     // 5D8
		PipboyLogData         logData;          // 718
		PipboyMapData         mapData;          // 7F0
		PipboyRadioData       radioData;        // A28
		PipboyPlayerInfoData  playerInfoData;   // AD8
		PipboyStatusData      statusData;       // BE0
		PipboyDataGroup*      dataGroups[11];   // CC0
		PipboyThrottleManager throttleManager;  // D18
	};
	static_assert(sizeof(PipboyDataManager) == 0xD48);
}
