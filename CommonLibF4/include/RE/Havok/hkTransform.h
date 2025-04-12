#pragma once

#include "RE/NetImmerse/NiMatrix3.h"

namespace RE
{
	class hkTransformf
	{
	public:
		hkTransformf(){};

		void SetIdentity()
		{
			rotation.MakeIdentity();
			translation = NiPoint4();
		}

		// members
		NiMatrix3 rotation;
		NiPoint4  translation;
	};

	using hkTransform = hkTransformf;
}
