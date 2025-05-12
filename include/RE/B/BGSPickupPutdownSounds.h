#pragma once

namespace RE
{
	class __declspec(novtable) BGSPickupPutdownSounds :
		public BaseFormComponent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BGSPickupPutdownSounds };
		static constexpr auto VTABLE{ VTABLE::BGSPickupPutdownSounds };

		// members
		BGSSoundDescriptorForm* pickupSound;   // 08
		BGSSoundDescriptorForm* putdownSound;  // 10
	};
	static_assert(sizeof(BGSPickupPutdownSounds) == 0x18);
}
