#pragma once

#include "RE/B/BSTSmartPointer.h"
#include "RE/E/ExtraDataList.h"
#include "RE/N/NiPoint.h"

namespace RE
{
	class BGSObjectInstanceExtra;
	class BGSPrimitive;
	class INSTANCE_FILTER;

	class __declspec(novtable) NEW_REFR_DATA
	{
	public:
		static constexpr auto RTTI{ RTTI::NEW_REFR_DATA };
		static constexpr auto VTABLE{ VTABLE::NEW_REFR_DATA };

		NEW_REFR_DATA()
		{
			stl::emplace_vtable(this);
		}

		virtual void HandlePre3D(TESObjectREFR*) { return; }

		// members
		NiPoint3                       location;                        // 08
		NiPoint3                       direction;                       // 14
		TESBoundObject*                object{ nullptr };               // 20
		TESObjectCELL*                 interior{ nullptr };             // 28
		TESWorldSpace*                 world{ nullptr };                // 30
		TESObjectREFR*                 reference{ nullptr };            // 38
		BGSPrimitive*                  addPrimitive{ nullptr };         // 40
		void*                          additionalData{ nullptr };       // 48
		BSTSmartPointer<ExtraDataList> extra{ nullptr };                // 50
		INSTANCE_FILTER*               instanceFilter{ nullptr };       // 58
		BGSObjectInstanceExtra*        modExtra{ nullptr };             // 60
		std::uint16_t                  maxLevel{ 0 };                   // 68
		bool                           forcePersist{ false };           // 6A
		bool                           clearStillLoadingFlag{ false };  // 6B
		bool                           initializeScripts{ true };       // 6C
		bool                           initiallyDisabled{ false };      // 6D
	};
	static_assert(sizeof(NEW_REFR_DATA) == 0x70);
}
