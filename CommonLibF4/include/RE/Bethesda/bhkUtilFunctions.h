#pragma once

#include "RE/Bethesda/BSTArray.h"
#include "RE/Havok/hkLocalArray.h"
#include "RE/Havok/hknpPhysicsSystem.h"
#include "RE/Havok/hknpPhysicsSystemData.h"
#include "RE/Havok/hkRefPtr.h"
#include "RE/NetImmerse/NiObject.h"

namespace RE
{
	class bhkNPCollisionObject;
	class NiAVObject;
}

namespace RE::bhkUtilFunctions
{
	inline bhkNPCollisionObject* FindFirstCollisionObject(NiAVObject* a_object)
	{
		using func_t = decltype(&bhkUtilFunctions::FindFirstCollisionObject);
		static REL::Relocation<func_t> func{ REL::ID(2278093) };
		return func(a_object);
	}
}
