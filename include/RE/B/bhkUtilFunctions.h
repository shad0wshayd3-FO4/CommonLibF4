#pragma once

namespace RE
{
	class bhkNPCollisionObject;
	class NiAVObject;

	namespace bhkUtilFunctions
	{
		inline bhkNPCollisionObject* FindFirstCollisionObject(NiAVObject* a_object)
		{
			using func_t = decltype(&bhkUtilFunctions::FindFirstCollisionObject);
			static REL::Relocation<func_t> func{ REL::ID(2278093) };
			return func(a_object);
		}
	}
}
