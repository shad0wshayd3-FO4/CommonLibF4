#pragma once

namespace Scaleform
{
	class __declspec(novtable) AcquireInterface
	{
	public:
		static constexpr auto RTTI{ RE::RTTI::Scaleform__AcquireInterface };
		static constexpr auto VTABLE{ RE::VTABLE::Scaleform__AcquireInterface };

		virtual ~AcquireInterface() = default;  // 00

		// add
		virtual bool CanAcquire();        // 01
		virtual bool TryAcquire();        // 02
		virtual bool TryAcquireCommit();  // 03
		virtual bool TryAcquireCancel();  // 04
	};
	static_assert(sizeof(AcquireInterface) == 0x8);
}
