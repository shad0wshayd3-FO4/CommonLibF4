#pragma once

namespace RE
{
	class BSMagicShaderParticles
	{
	public:
		using Filter = bool(NiAVObject*);

		// members
		BSModelDB::Handle protoSystem;         // 00
		NiPointer<NiNode> particlesRoot;       // 08
		bool              hasData;             // 10
		bool              attached;            // 11
		bool              stopped;             // 12
		bool              useSizeAdjustments;  // 13
		Filter* filterFunction;      // 18
	};
	static_assert(sizeof(BSMagicShaderParticles) == 0x20);
}
