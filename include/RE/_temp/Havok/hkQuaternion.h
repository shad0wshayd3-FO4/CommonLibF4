#pragma once

#include "RE/Havok/hkVector4.h"

namespace RE
{
	class hkQuaternionf
	{
	public:
		hkQuaternionf(){};  // empty constructor

		// members
		hkVector4f vec;
	};
	static_assert(sizeof(hkQuaternionf) == 0x10);

	using hkQuaternion = hkQuaternionf;
};
