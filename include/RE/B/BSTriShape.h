#pragma once

#include "RE/B/BSGeometry.h"
#include "RE/N/NiRTTI.h"

namespace RE
{
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
