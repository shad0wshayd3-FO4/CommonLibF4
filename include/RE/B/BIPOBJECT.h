#pragma once

#include "RE/N/NiPointer.h"
#include "RE/B/BSModelDB.h"
#include "RE/B/BGSObjectInstance.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	class BGSObjectInstanceExtra;
	class BGSTextureSet;
	class NiAVObject;
	class ModelReferenceEffect;
	class TESModel;
	class WeaponAnimationGraphManagerHolder;

	class BIPOBJECT
	{
	public:
		// members
		BGSObjectInstance                                  parent;              // 00
		BGSObjectInstanceExtra*                            modExtra;            // 10
		TESObjectARMA*                                     armorAddon;          // 18
		TESModel*                                          part;                // 20
		BGSTextureSet*                                     skinTexture;         // 28
		NiPointer<NiAVObject>                              partClone;           // 30
		BSModelDB::HandelListHead                          handleList;          // 38
		BSTSmartPointer<WeaponAnimationGraphManagerHolder> objectGraphManager;  // 40
		NiPointer<ModelReferenceEffect>                    hitEffect;           // 48
		bool                                               skinned;             // 50

	private:
		void Dtor()
		{
			using func_t = decltype(&BIPOBJECT::Dtor);
			static REL::Relocation<func_t> func{ REL::ID(765242) };
			return func(this);
		}
	};
	static_assert(sizeof(BIPOBJECT) == 0x58);
}
