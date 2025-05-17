#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	class ApplyColorUpdateEvent;
	class DoBeforeNewOrLoadCompletedEvent;
	class QueueSurvivalBumpDownMessage;
	class RevertPlayerCharacterEvent;
	class SaveLoadMessageTypeEvent;

	class __declspec(novtable) GameUIModel :
		public BSTSingletonSDM<GameUIModel>,
		public BSTEventSink<ApplyColorUpdateEvent>,
		public BSTEventSink<RevertPlayerCharacterEvent>,
		public BSTEventSink<DoBeforeNewOrLoadCompletedEvent>,
		public BSTEventSink<SaveLoadMessageTypeEvent>,
		public BSTEventSink<QueueSurvivalBumpDownMessage>
	{
	public:
		static constexpr auto RTTI{ RTTI::GameUIModel };
		static constexpr auto VTABLE{ VTABLE::GameUIModel };

		[[nodiscard]] static GameUIModel* GetSingleton()
		{
			static REL::Relocation<GameUIModel**> singleton{ ID::GameUIModel::Singleton };
			return *singleton;
		}

		void UpdateDataModels()
		{
			using func_t = decltype(&GameUIModel::UpdateDataModels);
			static REL::Relocation<func_t> func{ ID::GameUIModel::UpdateDataModels };
			return func(this);
		}
	};
}
