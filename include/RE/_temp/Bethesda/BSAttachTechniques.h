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

	class __declspec(novtable) RefAttachTechniqueInput :
		public BSAttachTechniques::AttachTechniqueInput  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::RefAttachTechniqueInput };
		static constexpr auto VTABLE{ VTABLE::RefAttachTechniqueInput };

		// members
		TESObjectREFR* object;           // 20
		TESRace*       race;             // 28
		bhkWorld*      havokWorld;       // 30
		std::uint32_t  collisionGroup;   // 38
		BSFixedString  techniqueSuffix;  // 40
	};
	static_assert(sizeof(RefAttachTechniqueInput) == 0x48);
}
