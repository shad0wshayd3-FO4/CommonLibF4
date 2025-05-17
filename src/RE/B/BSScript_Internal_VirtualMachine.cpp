#include "RE/B/BSScript_Internal_VirtualMachine.h"

#include "RE/G/GameScript.h"

namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			VirtualMachine* VirtualMachine::GetSingleton()
			{
				auto vm = GameVM::GetSingleton();
				return vm ? static_cast<VirtualMachine*>(vm->impl.get()) : nullptr;
			}
		}
	}
}
