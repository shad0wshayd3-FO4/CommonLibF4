#pragma once

namespace RE
{
	class __declspec(novtable) TESObject :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESObject };
		static constexpr auto VTABLE{ VTABLE::TESObject };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kNONE };

		// add
		virtual bool          IsBoundAnimObject() { return false; }                              // 4A
		virtual TESWaterForm* GetWaterType() const { return nullptr; }                           // 4B
		virtual bool          IsAutoCalc() const { return false; }                               // 4C
		virtual void          SetAutoCalc(bool) { return; }                                      // 4D
		virtual void          Clone3D(TESObjectREFR*, NiPointer<NiAVObject>&, bool) { return; }  // 4E
		virtual void          UnClone3D(TESObjectREFR* a_requester);                             // 4F
		virtual bool          IsMarker();                                                        // 50
		virtual bool          IsOcclusionMarker();                                               // 51
		virtual bool          ReplaceModel();                                                    // 52
		virtual std::uint32_t IncRef() { return 0; }                                             // 53
		virtual std::uint32_t DecRef() { return 0; }                                             // 54
		virtual NiAVObject*   LoadGraphics(TESObjectREFR* a_ref);                                // 55
	};
	static_assert(sizeof(TESObject) == 0x20);
}
