#pragma once

namespace RE
{
	class __declspec(novtable) hknpConvexPolytopeShape :
		public hknpConvexShape
	{
	public:
		inline static constexpr auto RTTI{ RTTI::hknpConvexPolytopeShape };
		inline static constexpr auto VTABLE{ VTABLE::hknpConvexPolytopeShape };

		struct Face
		{
			std::uint16_t firstIndex;
			std::uint8_t  numIndices;
			std::uint8_t  minHalfAngle;
		};

		// members
		hkRelArray<hkVector4f>   planes;   // 40
		hkRelArray<Face>         faces;    // 44
		hkRelArray<std::uint8_t> indices;  // 48
	};
	static_assert(sizeof(hknpConvexPolytopeShape) == 0x50);
}
