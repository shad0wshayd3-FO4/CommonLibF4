#pragma once

namespace RE
{
	enum class DEFAULT_OBJECT;

	class BSPackedTaskQueue;
	class NiAVObject;
	class TESAmmo;
	class TESObjectREFR;
	class TESObjectWEAP;

	class TaskQueueInterface
	{
	public:
		static TaskQueueInterface* GetSingleton()
		{
			static REL::Relocation<TaskQueueInterface**> singleton{ REL::ID(7491) };
			return *singleton;
		}

		void QueueClosePipboy()
		{
			using func_t = decltype(&TaskQueueInterface::QueueClosePipboy);
			static REL::Relocation<func_t> func{ REL::ID(69886) };
			return func(this);
		}

		void QueueRebuildBendableSpline(TESObjectREFR& a_ref, bool a_createPhysics, NiAVObject* a_childNode)
		{
			using func_t = decltype(&TaskQueueInterface::QueueRebuildBendableSpline);
			static REL::Relocation<func_t> func{ REL::ID(198419) };
			return func(this, a_ref, a_createPhysics, a_childNode);
		}

		void QueueShow1stPerson(bool a_show1stPerson)
		{
			using func_t = decltype(&TaskQueueInterface::QueueShow1stPerson);
			static REL::Relocation<func_t> func{ REL::ID(994377) };
			return func(this, a_show1stPerson);
		}

		void QueueShowPipboy(DEFAULT_OBJECT a_animType)
		{
			using func_t = decltype(&TaskQueueInterface::QueueShowPipboy);
			static REL::Relocation<func_t> func{ REL::ID(1133684) };
			return func(this, a_animType);
		}

		void QueueUpdate3D(TESObjectREFR* a_ref, std::uint32_t a_flags)
		{
			using func_t = decltype(&TaskQueueInterface::QueueUpdate3D);
			static REL::Relocation<func_t> func{ REL::ID(581890) };
			return func(this, a_ref, a_flags);
		}

		void QueueWeaponFire(TESObjectWEAP* a_weapon, TESObjectREFR* a_refObject, BGSEquipIndex a_equipIndex, TESAmmo* a_ammo)
		{
			using func_t = decltype(&TaskQueueInterface::QueueWeaponFire);
			static REL::Relocation<func_t> func{ REL::ID(15449) };
			return func(this, a_weapon, a_refObject, a_equipIndex, a_ammo);
		}

		// members
		BSPackedTaskQueue* queue;           // 00
		BSPackedTaskQueue* secondaryQueue;  // 08
		BSPackedTaskQueue* activeQueue;     // 18
	};
	static_assert(sizeof(TaskQueueInterface) == 0x18);
}
