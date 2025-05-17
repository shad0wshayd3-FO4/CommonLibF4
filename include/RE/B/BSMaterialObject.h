#pragma once

#include "RE/B/BSTArray.h"
#include "RE/N/NiPointer.h"
#include "RE/N/NiPoint.h"

namespace RE
{
	class NiProperty;

	class __declspec(novtable) BSMaterialObject
	{
	public:
		static constexpr auto RTTI{ RTTI::BSMaterialObject };
		static constexpr auto VTABLE{ VTABLE::BSMaterialObject };

		class DIRECTIONAL_DATA
		{
		public:
			// members
			float        falloffScale;     // 00
			float        falloffBias;      // 04
			float        noiseUVScale;     // 08
			float        materialUVScale;  // 0C
			NiPoint3     projectionDir;    // 10
			float        normalDampener;   // 1C
			float        red;              // 20
			float        green;            // 24
			float        blue;             // 28
			std::int32_t singlePass;       // 2C
		};
		static_assert(sizeof(DIRECTIONAL_DATA) == 0x30);

		virtual ~BSMaterialObject();  // 00

		// add
		virtual void EnsureLoaded() { return; }  // 01

		// members
		DIRECTIONAL_DATA                directionalData;  // 08
		BSTArray<NiPointer<NiProperty>> property;         // 38
	};
	static_assert(sizeof(BSMaterialObject) == 0x50);
}
