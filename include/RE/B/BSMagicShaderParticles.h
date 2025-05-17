#pragma once

#include "RE/N/NiPointer.h"

namespace RE
{
	class NiAVObject;
	class NiNode;

	class BSMagicShaderParticles
	{
	public:
		using Filter = bool(NiAVObject*);

		// members
		void*             protoSystem;         // 00 - BSModelDB::Handle
		NiPointer<NiNode> particlesRoot;       // 08
		bool              hasData;             // 10
		bool              attached;            // 11
		bool              stopped;             // 12
		bool              useSizeAdjustments;  // 13
		Filter*           filterFunction;      // 18
	};
	static_assert(sizeof(BSMagicShaderParticles) == 0x20);
}
