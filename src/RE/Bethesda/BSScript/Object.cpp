#include "RE/Bethesda/BSScript/Object.h"
#include "RE/Bethesda/BSScript/Internal/VirtualMachine.h"
namespace RE::BSScript
{
	Object::~Object()
	{
		if (IsConstructed()) {
			const std::uint32_t size = type ? type->GetVariableCount() : 0;
			for (std::uint32_t i = 0; i < size; ++i) {
				variables[i].reset();
			}

			constructed = false;
			initialized = false;
		}

		auto lock = reinterpret_cast<std::uintptr_t>(lockStructure) & ~static_cast<std::uintptr_t>(1);
		if (lock) {
			stl::atomic_ref l{ lock };
			--l;
		}
	}
	ObjectTypeInfo* Object::GetTypeInfo()
	{
		return type.get();
	}

	const ObjectTypeInfo* Object::GetTypeInfo() const
	{
		return type.get();
	}

	void* Object::Resolve(std::uint32_t a_typeID) const
	{
		auto vm = Internal::VirtualMachine::GetSingleton();
		if (!vm) {
			return nullptr;
		}
		IObjectHandlePolicy& policy = vm->GetObjectHandlePolicy();
		auto                 myHandle = GetHandle();
		if (policy.HandleIsType(a_typeID, myHandle) && policy.IsHandleObjectAvailable(myHandle)) {
			return policy.GetObjectForHandle(a_typeID, myHandle);
		} else {
			return nullptr;
		}
	}
	Variable* Object::GetProperty(const BSFixedString& a_name)
	{
		return const_cast<Variable*>(
			const_cast<const Object*>(this)->GetProperty(a_name));
	}

	const Variable* Object::GetProperty(const BSFixedString& a_name) const
	{
		constexpr auto INVALID = static_cast<std::uint32_t>(-1);

		auto idx = INVALID;
		for (auto cls = type.get(); cls && idx == INVALID; cls = cls->GetParent()) {
			idx = cls->GetPropertyIndex(a_name);
		}

		return idx != INVALID ? std::addressof(variables[idx]) : nullptr;
	}

}