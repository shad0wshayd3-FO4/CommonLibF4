#pragma once

namespace RE
{
	class TESInitScriptEventSource :
		public BSTEventSource<TESInitScriptEvent>
	{
	public:
		[[nodiscard]] static TESInitScriptEventSource* GetSingleton()
		{
			static REL::Relocation<TESInitScriptEventSource*> singleton{ REL::ID(2691330) };
			return singleton.get();
		}
	};
}
