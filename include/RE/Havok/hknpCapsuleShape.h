#pragma once

#include "RE/Havok/hkVector4.h"
#include "RE/Havok/hknpConvexPolytopeShape.h"

namespace RE
{
	class __declspec(novtable) hknpCapsuleShape :
		public hknpConvexPolytopeShape
	{
	public:
		inline static constexpr auto RTTI{ RTTI::hknpCapsuleShape };
		inline static constexpr auto VTABLE{ VTABLE::hknpCapsuleShape };

		void Init(const hkVector4f& a_posA, const hkVector4f& a_posB)
		{
			using func_t = decltype(&hknpCapsuleShape::Init);
			static REL::Relocation<func_t> func{ REL::ID(2257217) };
			return func(this, a_posA, a_posB);
		}

		static hknpCapsuleShape* CreateCapsuleShape(const hkVector4f& a_posA, const hkVector4f& a_posB, float a_radius)
		{
			using func_t = decltype(&hknpCapsuleShape::CreateCapsuleShape);
			static REL::Relocation<func_t> func{ REL::ID(2257207) };
			return func(a_posA, a_posB, a_radius);
		}

		// members
		hkVector4f a;  // 50
		hkVector4f b;  // 60
	};
	static_assert(sizeof(hknpCapsuleShape) == 0x70);
}
