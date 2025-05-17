#pragma once

#include "RE/P/PTYPE.h"

namespace RE
{
	class ActorPackageLoadFormBuffer;
	class BGSSaveFormBuffer;
	class IProcedureTreeExecState;

	class __declspec(novtable) ActorPackageData
	{
	public:
		static constexpr auto RTTI{ RTTI::ActorPackageData };
		static constexpr auto VTABLE{ VTABLE::ActorPackageData };

		virtual ~ActorPackageData();  // 00

		// add
		virtual PTYPE                    GetPackageType() = 0;                                                                              // 01
		virtual IProcedureTreeExecState* GetProcedureExecState() { return nullptr; }                                                        // 02
		virtual void                     SetProcedureExecState([[maybe_unused]] IProcedureTreeExecState& a_procedureExecState) { return; }  // 03
		virtual void                     ClearProcedureExecState() { return; }                                                              // 04
		virtual void                     SaveGame(BGSSaveFormBuffer* a_saveGameBuffer) = 0;                                                 // 05
		virtual void                     LoadGame(ActorPackageLoadFormBuffer* a_loadGameBuffer) = 0;                                        // 06
		virtual void                     InitLoadGame([[maybe_unused]] ActorPackageLoadFormBuffer* a_loadGameBuffer) { return; }            // 07
		virtual void                     ResetPackData([[maybe_unused]] TESPackage* a_pack) { return; }                                     // 08
	};
	static_assert(sizeof(ActorPackageData) == 0x8);
}
