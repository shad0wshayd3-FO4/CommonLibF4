#pragma once

namespace RE
{
	class __declspec(novtable) BGSMessageIcon :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSMessageIcon };
		static constexpr auto VTABLE{ VTABLE::BGSMessageIcon };

		// override (BaseFormComponent)
		void InitializeDataComponent() override;          // 02
		void ClearDataComponent() override;               // 03
		void CopyComponent(BaseFormComponent*) override;  // 06

		[[nodiscard]] const BSFixedString& GetMessageIconTextureName() const noexcept { return icon.textureName; }
		void                               SetMessageIconTextureName(BSFixedString a_texture) { icon.textureName = std::move(a_texture); }

		// members
		TESIcon icon;  // 08
	};
	static_assert(sizeof(BGSMessageIcon) == 0x18);
}
