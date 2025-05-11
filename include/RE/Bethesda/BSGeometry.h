#pragma once

#include "RE/Bethesda/BSGraphics.h"
#include "RE/NetImmerse/NiAVObject.h"
#include "RE/NetImmerse/NiProperty.h"

namespace RE
{
	class BSCombinedTriShape;
	class BSGeometrySegmentData;
	class BSMergeInstancedTriShape;
	class BSMultiIndexTriShape;

	namespace BSGraphics
	{
		struct IndexBuffer;
	}

	namespace BSSkin
	{
		class Instance;
	}

	class __declspec(novtable) BSGeometry :
		public NiAVObject  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSGeometry };
		static constexpr auto VTABLE{ VTABLE::BSGeometry };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSGeometry };

		BSGeometry();
		virtual ~BSGeometry();  // NOLINT(modernize-use-override) 00

		// add
		virtual void                      UpdatePropertyControllers(NiUpdateData& a_data);  // 3A
		virtual BSGeometrySegmentData*    GetSegmentData();                                 // 3B
		virtual void                      SetSegmentData(BSGeometrySegmentData* a_data);    // 3C
		virtual BSGraphics::IndexBuffer*  GetCustomIndexBuffer();                           // 3D
		virtual BSCombinedTriShape*       IsBSCombinedTriShape();                           // 3E
		virtual BSMergeInstancedTriShape* IsBSMergeInstancedTriShape();                     // 3F
		virtual BSMultiIndexTriShape*     IsMultiIndexTriShape();                           // 40
		virtual std::uint32_t             GetRenderableTris(std::uint32_t a_LODMode);       // 40

		// members
		NiBound                     modelBound;     // 120
		NiPointer<NiProperty>       properties[2];  // 130
		NiPointer<BSSkin::Instance> skinInstance;   // 140
		void*                       rendererData;   // 148
		BSGraphics::VertexDesc      vertexDesc;     // 150
		std::uint8_t                type;           // 158
		bool                        registered;     // 159
	};
	static_assert(sizeof(BSGeometry) == 0x160);

	class __declspec(novtable) BSTriShape :
		public BSGeometry  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSTriShape };
		static constexpr auto VTABLE{ VTABLE::BSTriShape };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSTriShape };

		BSTriShape();
		~BSTriShape() override;  // 00

		// override (BSGeometry)
		const NiRTTI* GetRTTI() const override  // 02
		{
			static REL::Relocation<const NiRTTI*> rtti{ BSTriShape::Ni_RTTI };
			return rtti.get();
		}

		BSTriShape* IsTriShape() override { return this; }                // 0A
		NiObject*   CreateClone(NiCloningProcess& a_cloneData) override;  // 1A
		void        LoadBinary(NiStream& a_stream) override;              // 1B
		void        LinkObject(NiStream& a_stream) override;              // 1C - { BSGeometry::LinkObject(a_stream); }
		bool        RegisterStreamables(NiStream& a_stream) override;     // 1D - { return BSGeometry::RegisterStreamables(a_stream); }
		void        SaveBinary(NiStream& a_stream) override;              // 1E
		bool        IsEqual(NiObject* a_object) override;                 // 1F - { return false; }

		// members
		std::uint32_t numTriangles;  // 160
		std::uint16_t numVertices;   // 164
	};
	static_assert(sizeof(BSTriShape) == 0x170);
}
