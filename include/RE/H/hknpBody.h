#pragma once

namespace RE
{
	class hknpBody
	{
	public:
		enum class SpuFlagsEnum : std::int32_t
		{
			kForceNarrowPhasePPU = 0x1
		};

		// members
		hkTransformf                        transform;
		hknpCollisionFlags                  flags;
		std::uint32_t                       collisionFilterInfo;
		const hknpShape*                    shape;
		hkAabb16                            aabb;
		hknpBodyId                          id;
		hknpBodyId                          nextAttachedBodyId;
		hknpMotionId                        motionId;
		std::uint32_t                       broadPhaseId;
		hknpMaterialId                      materialId;
		hknpBodyQualityId                   qualityId;
		std::uint8_t                        timAngle;
		std::uint16_t                       maxTimDistance;
		std::uint16_t                       maxContactDistance;
		std::uint32_t                       indexIntoActiveListOrDeactivatedIslandId;
		hkHalf                              radiusOfComCenteredBoundingSphere;
		hkFlags<SpuFlagsEnum, std::uint8_t> spuFlags;
		std::uint8_t                        shapeSizeDiv16;
		std::uint16_t                       motionToBodyRotation[4];  // hkPackedUnitVector<4>
		std::uint64_t                       userData;
	};
	static_assert(sizeof(hknpBody) == 0x90);
}
