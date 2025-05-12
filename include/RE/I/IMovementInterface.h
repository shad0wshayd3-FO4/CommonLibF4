#pragma once

namespace RE
{
	struct __declspec(novtable) IMovementInterface
	{
	public:
		static constexpr auto RTTI{ RTTI::IMovementInterface };
		static constexpr auto VTABLE{ VTABLE::IMovementInterface };

		virtual ~IMovementInterface() = default;  // 00
	};
	static_assert(sizeof(IMovementInterface) == 0x8);
}
