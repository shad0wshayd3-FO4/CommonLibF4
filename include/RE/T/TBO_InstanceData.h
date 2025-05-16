#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	class NiAVObject;

	class __declspec(novtable) TBO_InstanceData :
		public BSIntrusiveRefCounted  // 08
	{
	public:
		static constexpr auto RTTI{ RTTI::TBO_InstanceData };
		static constexpr auto VTABLE{ VTABLE::TBO_InstanceData };

		virtual ~TBO_InstanceData() = default;  // 00

		// add
		virtual BGSKeywordForm*             GetKeywordData() const { return nullptr; }                                    // 01
		virtual void                        DeleteKeywordData() { return; }                                               // 02
		virtual void                        CreateKeywordData() { return; }                                               // 03
		virtual BGSBlockBashData*           GetBlockBashData() const { return nullptr; }                                  // 04
		virtual void                        DeleteBlockBashData() { return; }                                             // 05
		virtual void                        CreateBlockBashData() { return; }                                             // 06
		virtual BSTArray<EnchantmentItem*>* GetEnchantmentArray() const { return nullptr; }                               // 07
		virtual void                        DeleteEnchantmentArray() { return; }                                          // 08
		virtual void                        CreateEnchantmentArray() { return; }                                          // 09
		virtual BSTArray<BGSMaterialSwap*>* GetMaterialSwapArray() const { return nullptr; }                              // 0A
		virtual void                        DeleteMaterialSwapArray() { return; }                                         // 0B
		virtual void                        CreateMaterialSwapArray() { return; }                                         // 0C
		virtual float                       GetWeight() const { return -1.0F; }                                           // 0D
		virtual std::int32_t                GetValue() const { return -1; }                                               // 0E
		virtual std::uint32_t               GetHealth() const { return 0; }                                               // 0F
		virtual float                       GetColorRemappingIndex() const { return std::numeric_limits<float>::max(); }  // 10
		virtual void                        PostAttach3D(NiAVObject* a_obj3D, TESObjectREFR* a_ref) const;                // 11
		virtual void                        PostApplyMods(const TESBoundObject*) { return; }                              // 12
	};
	static_assert(sizeof(TBO_InstanceData) == 0x10);
}
