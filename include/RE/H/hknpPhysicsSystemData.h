#pragma once

namespace RE
{
	class __declspec(novtable) hknpPhysicsSystemData :
		public hkReferencedObject
	{
	public:
		inline static constexpr auto RTTI{ RTTI::hknpPhysicsSystemData };
		inline static constexpr auto VTABLE{ VTABLE::hknpPhysicsSystemData };

		hknpPhysicsSystemData() = default;

		virtual ~hknpPhysicsSystemData();  // 00

		// members
		hkArray<hknpMaterial>                       materials;
		hkArray<hknpMotionProperties>               motionProperties;
		hkArray<hknpMotionCinfo>                    motionCinfos;
		hkArray<hknpBodyCinfo>                      bodyCinfos;
		hkArray<hknpConstraintCinfo>                constraintCinfos;
		hkArray<hkRefPtr<const hkReferencedObject>> referencedObjects;
		hkStringPtr                                 name;
	};
	static_assert(sizeof(hknpPhysicsSystemData) == 0x78);
}
