#pragma once

namespace RE
{
	class __declspec(novtable) DeviceConnectEvent :
		public InputEvent  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::DeviceConnectEvent };
		static constexpr auto VTABLE{ VTABLE::DeviceConnectEvent };
		static constexpr auto TYPE{ INPUT_EVENT_TYPE::kDeviceConnect };

		// NOLINTNEXTLINE(modernize-use-override)
		virtual ~DeviceConnectEvent() = default;  // 00

		// members
		bool connected{ true };  // 28
	};
	static_assert(sizeof(DeviceConnectEvent) == 0x30);

	extern template DeviceConnectEvent*       InputEvent::As() noexcept;
	extern template const DeviceConnectEvent* InputEvent::As() const noexcept;
}
