#pragma once

#include "RE/NetImmerse/NiObject.h"

namespace RE
{
	class NiUpdateData;

	class __declspec(novtable) NiCollisionObject :
		public NiObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::NiCollisionObject };
		static constexpr auto VTABLE{ VTABLE::NiCollisionObject };
		static constexpr auto Ni_RTTI{ Ni_RTTI::NiCollisionObject };

		// add
		virtual void SetSceneGraphObject(NiAVObject* a_sceneObject);                                               // 28
		virtual void UpdateWorldData(NiUpdateData& a_updateData);                                                  // 29
		virtual void Initialize([[maybe_unused]] void* a_data) { return; }                                         // 2A
		virtual void Convert([[maybe_unused]] std::uint32_t a_version, [[maybe_unused]] void* a_data) { return; }  // 2B

		// members
		NiAVObject* sceneObject;  // 10
	};
	static_assert(sizeof(NiCollisionObject) == 0x18);
}
