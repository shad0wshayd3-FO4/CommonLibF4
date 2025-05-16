#pragma once

#include "RE/B/BSTArray.h"

namespace RE
{
	class __declspec(novtable) BSISoundDescriptor
	{
	public:
		static constexpr auto RTTI{ RTTI::BSISoundDescriptor };
		static constexpr auto VTABLE{ VTABLE::BSISoundDescriptor };

		struct ExtraResolutionData;
		struct Resolution;

		virtual ~BSISoundDescriptor() = default;  // 00

		// add
		virtual bool DoResolve(Resolution& a_resolution, float a_distance, ExtraResolutionData* a_data) const = 0;   // 01
		virtual bool DoMultiResolve(BSScrapArray<Resolution>& a_resolution, ExtraResolutionData* a_data) const = 0;  // 02
		virtual bool DoAudibilityTest(float a_distance) const = 0;                                                   // 03
		virtual bool DoGetMultiResolves() const = 0;                                                                 // 04
	};
	static_assert(sizeof(BSISoundDescriptor) == 0x8);
}
