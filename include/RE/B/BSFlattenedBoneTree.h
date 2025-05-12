#pragma once

#include "RE/N/NiNode.h"

namespace RE
{
	class __declspec(novtable) BSFlattenedBoneTree :
		public NiNode  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSFlattenedBoneTree };
		static constexpr auto VTABLE{ VTABLE::BSFlattenedBoneTree };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSFlattenedBoneTree };

		struct FlattenedBone
		{
			NiTransform       local;
			NiTransform       world;
			std::int16_t      parent;
			std::int16_t      child;
			std::uint16_t     childCount;
			std::int16_t      sibling;
			NiPointer<NiNode> node;
			BSFixedString     name;
			bool              deferredAttach;
		};
		static_assert(sizeof(FlattenedBone) == 0xA0);

		BSFlattenedBoneTree() :
			NiNode(0)
		{
		}

		explicit BSFlattenedBoneTree(std::uint32_t a_numChildren) :
			NiNode(a_numChildren)
		{
			stl::emplace_vtable(this);
		}

		F4_HEAP_REDEFINE_ALIGNED_NEW(BSFlattenedBoneTree);

		// members
		std::int32_t                            boneCount{ 0 };
		std::int32_t                            boneCountExpanded{ 0 };
		FlattenedBone*                          bone{ nullptr };
		BSTHashMap<BSFixedString, std::int32_t> boneMap;
	};
	static_assert(sizeof(BSFlattenedBoneTree) == 0x180);
}
