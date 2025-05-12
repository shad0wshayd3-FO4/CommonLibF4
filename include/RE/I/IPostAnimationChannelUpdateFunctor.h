#pragma once

namespace RE
{
	class __declspec(novtable) IPostAnimationChannelUpdateFunctor
	{
	public:
		static constexpr auto RTTI{ RTTI::IPostAnimationChannelUpdateFunctor };
		static constexpr auto VTABLE{ VTABLE::IPostAnimationChannelUpdateFunctor };

		virtual ~IPostAnimationChannelUpdateFunctor() = default;  // 00

		// add
		virtual void DoPostAnimationChannelUpdate() = 0;  // 01
	};
	static_assert(sizeof(IPostAnimationChannelUpdateFunctor) == 0x8);
}
