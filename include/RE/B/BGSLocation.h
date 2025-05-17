#pragma once

#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BSTArray.h"
#include "RE/N/NiPointer.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"
#include "RE/B/BSTTuple.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSSpinLock.h"

namespace RE
{
	class OverrideData;
	class QueuedPromoteLocationReferencesTask;
	class SpecialRefData;
	class UniqueNPCData;

	class __declspec(novtable) BGSLocation :
		public TESForm,        // 000
		public TESFullName,    // 020
		public BGSKeywordForm  // 030
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSLocation };
		static constexpr auto VTABLE{ VTABLE::BGSLocation };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kLCTN };

		class KEYWORD_DATA
		{
		public:
			// members
			BGSKeyword* keyword;  // 00
			float       data;     // 08
		};
		static_assert(sizeof(KEYWORD_DATA) == 0x10);

		bool IsChild(const BGSLocation* a_possibleChild) const;
		bool IsParent(const BGSLocation* a_possibleParent) const;

		// members
		BGSLocation*                                           parentLoc;               // 050
		TESFaction*                                            unreportedCrimeFaction;  // 058
		BGSMusicType*                                          musicType;               // 060
		BGSEncounterZone*                                      zone;                    // 068
		ObjectRefHandle                                        worldLocMarker;          // 070
		float                                                  worldLocRadius;          // 074
		float                                                  actorFadeMult;           // 078
		ObjectRefHandle                                        horseLocMarker;          // 07C
		BSTArray<SpecialRefData>                               specialRefs;             // 080
		BSTArray<UniqueNPCData>                                uniqueNPCs;              // 098
		OverrideData*                                          overrideData;            // 0B0
		BSTArray<std::uint32_t>                                newUnloadedRefs;         // 0B8
		BSTArray<BSTTuple<BGSLocationRefType*, std::uint32_t>> newSpecialRefs;          // 0D0
		NiPointer<QueuedPromoteLocationReferencesTask>         promoteRefsTask;         // 0E8
		BSTArray<ObjectRefHandle>                              promotedRefsArray;       // 0F0
		volatile std::int32_t                                  loadedCount;             // 108
		std::uint32_t                                          fileOffset;              // 10C
		BSTArray<KEYWORD_DATA>                                 keywordData;             // 110
		BSSpinLock                                             locLoadedLock;           // 128
		std::uint32_t                                          lastChecked;             // 130
		bool                                                   cleared;                 // 134
		bool                                                   everCleared;             // 135
		BSReadWriteLock                                        locker;                  // 138
	};
	static_assert(sizeof(BGSLocation) == 0x140);
}
