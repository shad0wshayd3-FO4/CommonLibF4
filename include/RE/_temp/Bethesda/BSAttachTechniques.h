#pragma once

namespace RE
{
	class bhkWorld;
	class NiAVObject;
	class NiNode;
	class TESObjectREFR;
	class TESRace;

	namespace BSAttachTechniques
	{
		struct __declspec(novtable) AttachTechniqueInput
		{
		public:
			static constexpr auto RTTI{ RTTI::BSAttachTechniques__AttachTechniqueInput };
			static constexpr auto VTABLE{ VTABLE::BSAttachTechniques__AttachTechniqueInput };

			virtual ~AttachTechniqueInput();  // 00

			// add
			virtual void Clear();  // 01

			// members
			NiPointer<NiNode>     root;         // 08
			NiPointer<NiAVObject> attaching;    // 10
			std::uint32_t         attachPoint;  // 18
		};
		static_assert(sizeof(AttachTechniqueInput) == 0x20);
	}
}
