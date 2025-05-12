#pragma once

namespace RE
{
	class __declspec(novtable) BGSShaderParticleGeometryData :
		public TESForm  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSShaderParticleGeometryData };
		static constexpr auto VTABLE{ VTABLE::BGSShaderParticleGeometryData };
		static constexpr auto FORM_ID{ ENUM_FORM_ID::kSPGD };

		// members
		BSTArray<SETTING_VALUE> data;             // 20
		TESTexture              particleTexture;  // 38
		BSFixedString           materialName;     // 48
	};
	static_assert(sizeof(BGSShaderParticleGeometryData) == 0x50);
}
