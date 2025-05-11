#include "RE/Bethesda/BSScript/Internal/VirtualMachine.h"
#include "RE/Bethesda/GameScript.h"
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
