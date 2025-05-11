#pragma once

namespace RE
{
	class NiPoint2;
	class NiPoint3;
	class NiColorA;
}

namespace RE::BSGraphics::Utility
{
	inline void ConvertHALFToNiPoint3Stream(const std::uint16_t* a_src, NiPoint3* a_dst, std::uint32_t a_count, std::uint32_t a_stride)
	{
		using func_t = decltype(&ConvertHALFToNiPoint3Stream);
		static REL::Relocation<func_t> func{ REL::ID(2277113) };
		func(a_src, a_dst, a_count, a_stride);
	}

	inline void ConvertNiPoint3ToHALFStream(const NiPoint3* a_src, std::uint16_t* a_dst, std::uint32_t a_count)
	{
		using func_t = decltype(&ConvertNiPoint3ToHALFStream);
		static REL::Relocation<func_t> func{ REL::ID(2277114) };
		func(a_src, a_dst, a_count);
	}

	inline std::uint64_t PackVertexData(
		std::uint32_t  a_numVertices,
		NiPoint3*      a_positions,
		NiPoint2*      a_texCoords0,
		NiColorA*      a_texCoords1,
		NiPoint3*      a_normals,
		NiPoint3*      a_binormals,
		NiPoint3*      a_tangents,
		NiColorA*      a_colors,
		NiColorA*      a_skinBoneWeights,
		std::uint8_t*  a_skinBoneIndices,
		NiColorA*      a_landscapeData1,
		NiColorA*      a_landscapeData2,
		float*         a_eyeData,
		void*          a_buffer,
		std::uint32_t* a_bufferSize,
		std::uint16_t* a_vertexMap,
		std::uint32_t  a_dynamicFlags,
		std::uint16_t* a_tangentXBuffer,
		std::uint32_t  a_tangentXBufferStride)
	{
		using func_t = decltype(&PackVertexData);
		static REL::Relocation<func_t> func{ REL::ID(2277106) };
		return func(a_numVertices, a_positions, a_texCoords0, a_texCoords1, a_normals, a_binormals, a_tangents, a_colors, a_skinBoneWeights, a_skinBoneIndices, a_landscapeData1, a_landscapeData2, a_eyeData, a_buffer, a_bufferSize, a_vertexMap, a_dynamicFlags, a_tangentXBuffer, a_tangentXBufferStride);
	}

	inline void UnpackVertexData(
		const std::uint8_t* a_vertices,
		const std::uint16_t a_index,
		const std::uint64_t a_vertexDesc,
		NiPoint3*           a_position,
		NiPoint2*           a_texCoord0,
		NiPoint2*           a_texCoord1,
		NiPoint3*           a_normal,
		NiPoint3*           a_binormal,
		NiPoint3*           a_tangent,
		NiColorA*           a_color,
		NiColorA*           a_skinBoneWeights,
		std::uint8_t*       a_boneIndex0,
		std::uint8_t*       a_boneIndex1,
		std::uint8_t*       a_boneIndex2,
		std::uint8_t*       a_boneIndex3)
	{
		using func_t = decltype(&UnpackVertexData);
		static REL::Relocation<func_t> func{ REL::ID(2277129) };
		func(a_vertices, a_index, a_vertexDesc, a_position, a_texCoord0, a_texCoord1, a_normal, a_binormal, a_tangent, a_color, a_skinBoneWeights, a_boneIndex0, a_boneIndex1, a_boneIndex2, a_boneIndex3);
	}
}
