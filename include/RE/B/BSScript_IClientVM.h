#pragma once

namespace RE
{
	namespace BSScript
	{
		class __declspec(novtable) IClientVM
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__IClientVM };
			static constexpr auto VTABLE{ VTABLE::BSScript__IClientVM };

			virtual ~IClientVM();  // 00

			// add
			virtual bool IsVMFrozen() const;  // 01
			virtual void PreSave();           // 02
		};
		static_assert(sizeof(IClientVM) == 0x8);
	}
}
