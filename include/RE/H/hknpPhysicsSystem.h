#pragma once

namespace RE
{
	class __declspec(novtable) hknpPhysicsSystem :
		public hkReferencedObject
	{
	public:
		static constexpr auto RTTI{ RTTI::hknpPhysicsSystem };
		static constexpr auto VTABLE{ VTABLE::hknpPhysicsSystem };

		enum class Flags : std::int32_t
		{
			CLONE_POWERABLE_CONSTRAINT_DATAS = 0x1,
			FORCE_EXPORTABLE_CONSTRAINTS = 0x2,
			CREATE_CONSTRAINTS = 0x4,
			DEFAULT_FLAGS = 0x5,
		};

		virtual ~hknpPhysicsSystem();  // 00

		void AddToWorld(hknpWorld::AdditionMode a_additionMode, hkFlags<hknpWorld::AdditionFlagsEnum, std::uint8_t> a_additionFlags, hknpActivationMode::Enum a_constraintActivationMode)
		{
			using func_t = decltype(&hknpPhysicsSystem::AddToWorld);
			static REL::Relocation<func_t> func{ REL::ID(2255984) };
			func(this, a_additionMode, a_additionFlags, a_constraintActivationMode);
		}

		void RemoveFromWorld()
		{
			using func_t = decltype(&hknpPhysicsSystem::RemoveFromWorld);
			static REL::Relocation<func_t> func{ REL::ID(2255985) };
			func(this);
		}

		// members
		hkRefPtr<const hknpPhysicsSystemData> data;
		hkRefPtr<hknpWorld>                   world;
		hkArray<hknpBodyId>                   bodyIds;
		hkArray<hknpConstraintId>             constraintIds;
	};
	static_assert(sizeof(hknpPhysicsSystem) == 0x40);
}
