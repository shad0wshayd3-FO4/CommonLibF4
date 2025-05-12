#pragma once

namespace RE
{
	class __declspec(novtable) bhkNPCollisionObjectUnlinked :
		public bhkNPCollisionObject  // 00
	{
	public:
		inline static constexpr auto RTTI{ RTTI::bhkNPCollisionObjectUnlinked };
		inline static constexpr auto VTABLE{ VTABLE::bhkNPCollisionObjectUnlinked };
		inline static constexpr auto Ni_RTTI{ Ni_RTTI::bhkNPCollisionObjectUnlinked };

		class LinkExtraData :
			public NiExtraData
		{
		public:
			inline static constexpr auto RTTI{ RTTI::bhkNPCollisionObjectUnlinked__LinkExtraData };
			inline static constexpr auto VTABLE{ VTABLE::bhkNPCollisionObjectUnlinked__LinkExtraData };

			// members
			BSTSet<NiPointer<bhkNPCollisionObjectUnlinked>> linkedCollisionObjSet;
		};
	};
	static_assert(sizeof(bhkNPCollisionObjectUnlinked) == 0x30);
}
