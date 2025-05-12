#pragma once

namespace RE
{
	class __declspec(novtable) TESBoundObject :
		public TESObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESBoundObject };
		static constexpr auto VTABLE{ VTABLE::TESBoundObject };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kNONE };

		struct BOUND_DATA
		{
		public:
			// members
			NiNPShortPoint3 boundMin;  // 00
			NiNPShortPoint3 boundMax;  // 06
		};
		static_assert(sizeof(BOUND_DATA) == 0xC);

		// add
		virtual TBO_InstanceData*       CreateInstanceData(const TBO_InstanceData*) const { return nullptr; }                                                     // 56
		virtual const TBO_InstanceData* GetBaseInstanceData() const { return nullptr; }                                                                           // 57
		virtual bool                    GetAttachedMarkersVisible(NiAVObject*) const { return false; }                                                            // 58
		virtual void                    SetAttachedMarkersVisible(NiAVObject*, bool) const { return; }                                                            // 59
		virtual bool                    QSupportsCountPerInstance() const { return false; }                                                                       // 5A
		virtual void                    SetObjectVoiceType(BGSVoiceType*) { return; }                                                                             // 5B
		virtual BGSVoiceType*           GetObjectVoiceType() const { return nullptr; }                                                                            // 5C
		virtual BGSSoundDescriptorForm* GetSoundForTag(const BSFixedString& a_tag) const;                                                                         // 5D
		virtual void                    Clone3D(TESObjectREFR* a_requester, NiPointer<NiAVObject>& a_obj3D) { TESObject::Clone3D(a_requester, a_obj3D, false); }  // 5E
		virtual bool                    ReplaceModel(const char* a_filename);                                                                                     // 5F
		virtual bool                    GetActivateText(TESObjectREFR* a_itemActivated, BSStringT<char>& a_resultString);                                         // 60
		virtual COMMAND_REFUSAL_TYPE    CalculateDoFavor(Actor* a_actor, bool a_owned, TESObjectREFR*, float a_moralityMult) const;                               // 61
		virtual void                    HandleRemoveItemFromContainer(TESObjectREFR*) { return; }                                                                 // 62
		virtual void                    OnRemove3D(NiAVObject*) { return; }                                                                                       // 63
		virtual void                    OnCheckModels() { return; }                                                                                               // 64
		virtual void                    OnCopyReference() { return; }                                                                                             // 65
		virtual void                    OnFinishScale() { return; }                                                                                               // 66

		void ApplyMods(BSTSmartPointer<TBO_InstanceData>& a_dest, const BGSObjectInstanceExtra* a_extra) const
		{
			using func_t = decltype(&TESBoundObject::ApplyMods);
			static REL::Relocation<func_t> func{ REL::ID(2198325) };
			return func(this, a_dest, a_extra);
		}

		// members
		BOUND_DATA              boundData;          // 20
		BGSMod::Template::Items objectTemplate;     // 30
		BGSPreviewTransform     previewTransform;   // 50
		BGSSoundTagComponent    soundTagComponent;  // 60
	};
	static_assert(sizeof(TESBoundObject) == 0x68);
}
