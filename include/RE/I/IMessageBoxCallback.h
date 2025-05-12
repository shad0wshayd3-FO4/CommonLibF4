#pragma once

namespace RE
{
	class alignas(0x10) IMessageBoxCallback :
		public BSIntrusiveRefCounted  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::IMessageBoxCallback };
		static constexpr auto VTABLE{ VTABLE::IMessageBoxCallback };

		virtual ~IMessageBoxCallback() = default;  // 00

		// add
		virtual void operator()(std::uint8_t a_buttonIdx) = 0;  // 01
	};
	static_assert(sizeof(IMessageBoxCallback) == 0x10);
}
