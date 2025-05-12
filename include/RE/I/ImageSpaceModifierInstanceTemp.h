#pragma once

namespace RE
{
	class ImageSpaceModifierInstanceTemp :
		public ImageSpaceModifierInstance  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::ImageSpaceModifierInstanceTemp };
		static constexpr auto VTABLE{ VTABLE::ImageSpaceModifierInstanceTemp };

		virtual ~ImageSpaceModifierInstanceTemp();  // 00

		// override (ImageSpaceModifierInstance)
		virtual bool IsExpired() override;                // 28
		virtual void PrintInfo(char* a_buffer) override;  // 2A

		// members
		float duration;  // 28
	};
	static_assert(sizeof(ImageSpaceModifierInstanceTemp) == 0x30);
}
