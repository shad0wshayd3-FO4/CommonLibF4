#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class __declspec(novtable) TESTexture :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::TESTexture };
		static constexpr auto VTABLE{ VTABLE::TESTexture };

		// override (BaseFormComponent)
		void InitializeDataComponent() override;          // 02
		void ClearDataComponent() override { return; }    // 03
		void CopyComponent(BaseFormComponent*) override;  // 06

		// add
		virtual std::uint32_t GetMaxAllowedSize() { return 0; }                // 07
		virtual const char*   GetAsNormalFile(BSString& a_outFilename) const;  // 08
		virtual const char*   GetDefaultPath() const { return "Textures\\"; }  // 09

		// members
		BSFixedString textureName;  // 08
	};
	static_assert(sizeof(TESTexture) == 0x10);
}
